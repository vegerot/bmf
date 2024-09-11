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

#ifndef _BMFLITE_DEMO_PLAYER_H_
#define _BMFLITE_DEMO_PLAYER_H_

#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>
#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>
#import "BmfLiteDemoOptions.h"

@interface BmfLiteDemoPlayer : NSObject

- (instancetype)initWithMTKView:(MTKView *)
                           view:(int)mode
                               :(BmfLiteDemoAlgoType)algo_type;

- (void)setSliderValue:(float)value;

- (void)consume:(CMSampleBufferRef)sampleBuffer:(BOOL)compare;

@end

#endif /* _BMFLITE_DEMO_PLAYER_H_ */
