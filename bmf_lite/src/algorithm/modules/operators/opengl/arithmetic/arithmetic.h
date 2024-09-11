/*
 * Copyright 2023 Babit Authors
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
#ifndef _BMF_ALGORITHM_MODULES_OPS_OPENGL_ARITHMETIC_H_
#define _BMF_ALGORITHM_MODULES_OPS_OPENGL_ARITHMETIC_H_
#include <string>
#include "opengl/gl_helper.h"

namespace bmf_lite {
namespace opengl {

/**
 * @brief Arithmetic texA * a + texB * b + c
 *
 */
class Arithmetic {
  public:
    int init(const std::string &program_cache_dir);
    /**
     * @brief
     *
     * @param in_tex0
     * @param in_tex1
     * @param out_tex
     * @param width
     * @param height
     * @param a
     * @param b
     * @param c
     * @return BMF_LITE_ERROR_CODE
     */
    int run(GLuint in_tex0, GLuint in_tex1, GLuint out_tex, int width,
            int height, float a, float b, float c);

    ~Arithmetic();

  private:
    GLuint program_id_ = GL_NONE;

    GLint local_size_[3] = {16, 16, 1};

    bool inited_ = false;
}; // Arithmetic

} // namespace opengl
} // namespace bmf_lite
#endif
