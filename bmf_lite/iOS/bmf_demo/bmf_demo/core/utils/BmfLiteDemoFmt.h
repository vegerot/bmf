/*
 * Copyright 2024 Babit Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BMFLITE_DEMO_FMT_H_
#define _BMFLITE_DEMO_FMT_H_

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <Metal/Metal.h>

@interface BmfLiteDemoFmt : NSObject

@property(atomic, assign, readwrite) OSType pixel_buffer_fmt;

@property(atomic, assign, readwrite) MTLPixelFormat tex0_fmt;

@property(atomic, assign, readwrite) MTLPixelFormat tex1_fmt;

@property(atomic, assign, readwrite) MTLPixelFormat tex2_fmt;

@property(atomic, assign, readwrite) int plane_count;

- (instancetype)initWithCVPixelBufferFormat:(OSType)fmt;

- (MTLPixelFormat)getTexFormatByPlane:(int)plane;

- (int)getPlaneCount;

- (int)getWidthByPlaneIndex:(uint32_t)index WithOriginWidth:(int)width;

- (int)getHeightByPlaneIndex:(int)index WithOriginHeight:(int)height;
@end

#endif /* _BMFLITE_DEMO_FMT_H_ */
