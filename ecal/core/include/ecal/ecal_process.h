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
 * @file   ecal_process.h
 * @brief  eCAL process interface
**/

#pragma once

#include <chrono>
#include <string>

#include <ecal/ecal_deprecate.h>
#include <ecal/ecal_os.h>
#include <ecal/ecal_process_severity.h>
#include <ecal/ecal_callback.h>

namespace eCAL
{
  namespace Process
  {
    /**
     * @brief  Dump configuration to console. 
    **/
    ECAL_API void DumpConfig();

    /**
     * @brief  Dump configuration to std::string.
     *
     * @param  cfg_s_  String to dump configuration to.
    **/
    ECAL_API void DumpConfig(std::string& cfg_s_);

    /**
     * @brief  Get current host name. 
     *
     * @return  Host name or empty string if failed. 
    **/
    ECAL_API std::string GetHostName();

    /**
     * @brief  Get current host group name.
     *
     * @return  Host group name or empty string if failed.
    **/
    ECAL_API std::string GetHostGroupName();

    /**
     * @brief  Get unique host id.
     *
     * @return  Host id or zero if failed.
    **/
    ECAL_DEPRECATE_SINCE_5_10("This function will be removed in eCAL6.")
    ECAL_API int GetHostID();

    /**
     * @brief  Get current unit name (defined via eCAL::Initialize). 
     *
     * @return  Unit name or empty string if failed. 
    **/
    ECAL_API std::string GetUnitName();

    /**
     * @brief  Get current process parameter (defined via eCAL::Initialize(argc_, arg_v). 
     *
     * @param sep_  Separator. 
     *
     * @return  Task parameter separated by 'sep_' or zero string if failed. 
    **/
    ECAL_API std::string GetTaskParameter(const char* sep_);

    /**
     * @brief  Sleep current thread.
     *
     * Because of the fact that std::this_thread::sleep_for is vulnerable to system clock changes
     * on Windows, Sleep function from synchapi.h had to be used for Windows. This insures time
     * robustness on all platforms from a thread sleep perspective.
     *
     * @param  time_ms_  Time to sleep in ms.
    **/
    ECAL_API void SleepMS(long time_ms_);

    /**
     * @brief  Sleep current thread.
     *
     * Because of the fact that std::this_thread::sleep_for is vulnerable to system clock changes
     * on Windows, Sleep function from synchapi.h had to be used for Windows. This insures time
     * robustness on all platforms from a thread sleep perspective. Used with ns unit to obtain bigger precision.
     *
     * @param  time_ns_  Time to sleep in ns.
    **/
    ECAL_API void SleepNS(const long long time_ns_);

    /**
     * @brief  Sleep current thread.
     *
     * Templated implementation which takes as argument a std::chrono::duration and calls underlying SleepNS function.
     * By using a std::chrono::duration argument we ensure that conversion to ms would be more precise for Windows Sleep method.
     *
     * @param  time  Time to sleep expressed in std::chrono::duration.
    **/

    template <typename Rep, typename Period>
    void SleepFor( std::chrono::duration<Rep, Period> time )
    {
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time).count();
        SleepNS(ns);
    }

    /**
     * @brief  Get current process id. 
     *
     * @return  The process id. 
    **/
    ECAL_API int GetProcessID();

    /**
     * @brief  Get current process id as string.
     *
     * @return  The process id.
    **/
    ECAL_API std::string GetProcessIDAsString();

    /**
     * @brief  Get current process name. 
     *
     * @return  Process name length or zero if failed. 
    **/
    ECAL_API std::string GetProcessName();

    /**
     * @brief  Get current process parameter. 
     *
     * @return  Process parameter or empty string if failed. 
    **/
    ECAL_API std::string GetProcessParameter();

    /**
     * @brief  Set process state info. 
     *
     * @param severity_  Severity. 
     * @param level_     Severity level.
     * @param info_      Info message.
     *
    **/
    ECAL_API void SetState(eCAL_Process_eSeverity severity_, eCAL_Process_eSeverity_Level level_, const char* info_);

    /**
     * @brief  Add registration callback.
     *
     * @param event_          The type of registration.
     * @param callback_       The callback.
     *
     * @return  Zero if succeeded.
    **/
    ECAL_API int AddRegistrationCallback(enum eCAL_Registration_Event event_, RegistrationCallbackT callback_);

    /**
     * @brief  Remove registration callback.
     *
     * @param event_          The type of registration.
     *
     * @return  Zero if succeeded.
    **/
    ECAL_API int RemRegistrationCallback(enum eCAL_Registration_Event event_);
  }
  /** @example process.cpp
  * This is an example how functions from the eCAL::Process namespace may be used.
  */
}