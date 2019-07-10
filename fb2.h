//
// fb2.h
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _fb2_h
#define _fb2_h

#include "bcm_host.h"

class FrameBuffer2 {
public:
  FrameBuffer2();
  virtual ~FrameBuffer2();

  int Allocate(uint8_t **pixels, int width, int height, int *pitch);
  void Free();
  void Clear();

  // Get a pointer to raw pixel data for this frame buffer
  void* GetPixels();

  // Indicates raw pixel data has a complete frame. Upload to vc resource.
  void FrameReady();

  // Show the framebuffer over top the first
  void Show();

  // Hide the framebuffer
  void Hide();

  static void Initialize();
private:

  // Raw pixel data. Not VC memory.
  uint8_t* pixels_;

  static DISPMANX_DISPLAY_HANDLE_T dispman_display_;
  DISPMANX_ELEMENT_HANDLE_T dispman_element_;
  DISPMANX_RESOURCE_HANDLE_T dispman_resource_;

  VC_RECT_T dst_rect_;
  VC_RECT_T src_rect_;
  VC_DISPMANX_ALPHA_T alpha_;

  static bool initialized_;

  int width_;
  int height_;
  int pitch_;

  int display_width_;
  int display_height_;

  bool showing_;
  bool allocated_;
};

#endif