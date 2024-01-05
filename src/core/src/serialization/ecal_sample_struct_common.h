/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

/**
 * @file   ecal_sample_struct_common.h
 * @brief  eCAL common struct types
**/

#pragma once

namespace eCAL
{
  enum eCmdType
  {
    bct_none             = 0,
    bct_set_sample       = 1,
    bct_reg_publisher    = 2,
    bct_reg_subscriber   = 3,
    bct_reg_process      = 4,
    bct_unreg_publisher  = 12,
    bct_unreg_subscriber = 13,
    bct_unreg_process    = 14
  };

  enum eTLayerType
  {
    tl_none        = 0,
    tl_ecal_udp_mc = 1,
    tl_all         = 255,
  };
}
