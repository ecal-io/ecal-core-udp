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
 * @file   ecal_publisher_cimpl.h
 * @brief  eCAL publisher c interface
**/

#ifndef ecal_publisher_cimpl_h_included
#define ecal_publisher_cimpl_h_included

#include <ecal/ecal_os.h>
#include <ecal/ecal_c_types.h>

#include <ecal/cimpl/ecal_callback_cimpl.h>

#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus*/
  /**
   * @brief Instance a publisher.
   *
   * @return  Handle to new publisher or NULL if failed.
  **/
  ECALC_API ECAL_HANDLE eCAL_Pub_New();

  /**
   * @brief Create a publisher. 
   *
   * @param handle_          Publisher handle.
   * @param topic_name_      Unique topic name.
   * @param topic_type_      Topic type name. 
   * @param topic_desc_      Topic type description. 
   * @param topic_desc_len_  Topic type description length. 
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_Create(ECAL_HANDLE handle_, const char* topic_name_, const char* topic_type_, const char* topic_desc_, int topic_desc_len_);

  /**
   * @brief Destroy a publisher. 
   *
   * @param handle_  Publisher handle. 
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_Destroy(ECAL_HANDLE handle_);

  /**
   * @brief Setup topic type name.
   *
   * @param handle_               Publisher handle.
   * @param topic_type_name_      Topic type name.
   * @param topic_type_name_len_  Topic type name length.
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_SetTypeName(ECAL_HANDLE handle_, const char* topic_type_name_, int topic_type_name_len_);

  /**
   * @brief Setup topic type description. 
   *
   * @param handle_          Publisher handle. 
   * @param topic_desc_      Topic type description. 
   * @param topic_desc_len_  Topic type description length. 
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_SetDescription(ECAL_HANDLE handle_, const char* topic_desc_, int topic_desc_len_);

  /**
   * @brief Sets publisher attribute. 
   *
   * @param handle_             Publisher handle. 
   * @param attr_name_          Attribute name. 
   * @param attr_name_len_      Attribute name length. 
   * @param attr_value_         Attribute value. 
   * @param attr_value_len_     Attribute value length. 
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_SetAttribute(ECAL_HANDLE handle_, const char* attr_name_, int attr_name_len_, const char* attr_value_, int attr_value_len_);

  /**
   * @brief Removes publisher attribute. 
   *
   * @param handle_             Publisher handle. 
   * @param attr_name_          Attribute name. 
   * @param attr_name_len_      Attribute name length. 
   *
   * @return  None zero if succeeded.
   * @experimental
  **/
  ECALC_API int eCAL_Pub_ClearAttribute(ECAL_HANDLE handle_, const char* attr_name_, int attr_name_len_);

  /**
   * @brief Share topic type.
   *
   * @param handle_ Publisher handle. 
   * @param state_  Set type share mode (none zero == share type).
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_ShareType(ECAL_HANDLE handle_, int state_);

  /**
   * @brief Share topic description.
   *
   * @param handle_ Publisher handle. 
   * @param state_  Set description share mode (none zero == share description).
   *
   * @return  None zero if succeeded.
  **/
  ECALC_API int eCAL_Pub_ShareDescription(ECAL_HANDLE handle_, int state_);

  /**
   * @brief Set publisher maximum transmit bandwidth for the udp layer.
   *
   * @param handle_     Publisher handle.
   * @param bandwidth_  Maximum bandwidth in bytes/s (-1 == unlimited).
   *
   * @return  True if it succeeds, false if it fails.
  **/
  ECALC_API int eCAL_Pub_SetMaxBandwidthUDP(ECAL_HANDLE handle_, long bandwidth_);

  /**
   * @brief Set publisher maximum transmit bandwidth for the udp layer.
   *
   * @param handle_  Publisher handle.
   * @param id_      The topic id for subscriber side filtering (0 == no id).
   *
   * @return  True if it succeeds, false if it fails.
  **/
  ECALC_API int eCAL_Pub_SetID(ECAL_HANDLE handle_, long long id_);

  /**
   * @brief Query if the publisher is subscribed. 
   *
   * @param handle_  Publisher handle. 
   *
   * @return  None zero if subscribed. 
  **/
  ECALC_API int eCAL_Pub_IsSubscribed(ECAL_HANDLE handle_);

  /**
   * @brief Send a message to all subscribers. 
   *
   * @param handle_   Publisher handle. 
   * @param buf_      Buffer that contains content to send. 
   * @param buf_len_  Send buffer length. 
   * @param time_     Send time (-1 = use eCAL system time in us, default = -1).
   *
   * @return  Number of bytes sent. 
  **/
  ECALC_API int eCAL_Pub_Send(ECAL_HANDLE handle_, const void* const buf_, int buf_len_, long long time_);

  /**
   * @brief Dump the whole class state into a string buffer. 
   *
   * @param handle_         Publisher handle. 
   * @param [out] buf_      Pointer to store the monitoring information. 
   * @param       buf_len_  Length of allocated buffer or ECAL_ALLOCATE_4ME if
   *                        eCAL should allocate the buffer for you (see eCAL_FreeMem). 
   *
   * @return  Dump buffer length or zero if failed. 
  **/
  ECALC_API int eCAL_Pub_Dump(ECAL_HANDLE handle_, void* buf_, int buf_len_);
#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*ecal_publisher_cimpl_h_included*/
