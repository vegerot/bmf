/*
 * Copyright 2024 Babit Authors
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

#include "../include/split_module.h"
#include <bmf/sdk/log.h>

SplitModule::SplitModule(int node_id, JsonParam json_param)
    : Module(node_id, json_param) {
    BMFLOG_NODE(BMF_INFO, node_id_) << "split module";
    last_input_num_ = 0;
    last_output_num_ = 0;
    stream_index_ = 0;
    in_eof_ = false;
    return;
}

int SplitModule::process(Task &task) {
    if (task.get_inputs().size() != last_input_num_) {
        BMFLOG_NODE(BMF_DEBUG, node_id_)
            << "Input Queue size changed from " << last_input_num_ << " to "
            << task.get_inputs().size();
        last_input_num_ = task.get_inputs().size();
        if (last_input_num_ > 1) {
            BMFLOG_NODE(BMF_ERROR, node_id_)
                << "Input Queue size > 1 may be meet error!";
            close();
        }
    }
    if (task.get_outputs().size() != last_output_num_) {
        BMFLOG_NODE(BMF_DEBUG, node_id_)
            << "Output Queue size changed from " << last_output_num_ << " to "
            << task.get_outputs().size();
        last_output_num_ = task.get_outputs().size();
    }

    auto input_queue = task.get_inputs()[0];

    // Data Splitting
    Packet pkt;
    
    while (task.pop_packet_from_input_queue(0, pkt)) {
        
        if (in_eof_ == true)
            continue;
        // fill splitted pkt into multi output stream
        task.fill_output_packet(stream_index_, pkt);
        if (pkt.timestamp() == BMF_EOF) {
            // fill eof packet for extra distributed node
            for (size_t i = 1; i < task.get_outputs().size(); i++) {
                task.fill_output_packet(i, Packet::generate_eof_packet());
            }
            in_eof_ = true;
        }
        BMFLOG_NODE(BMF_DEBUG, node_id_)
            << "get packet :" << pkt.timestamp()
            << " data:" << pkt.type_info().name
            << " in queue:" << 0;

        stream_index_ = (stream_index_ + 1) % task.get_outputs().size();
    }

    if (in_eof_)
        task.set_timestamp(DONE);

    return 0;
}

int SplitModule::reset() {
    in_eof_ = false;
    return 0;
}

int SplitModule::close() { return 0; }