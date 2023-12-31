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
 * @brief  eCAL core functions
**/

#pragma once

#include "ecal_global_accessors.h"
#if ECAL_CORE_REGISTRATION
#include "registration/ecal_registration_provider.h"
#include "registration/ecal_registration_receiver.h"
#endif 
#include "time/ecal_timegate.h"
#include "logging/ecal_log_impl.h"
#if ECAL_CORE_PUBLISHER
#include "pubsub/ecal_pubgate.h"
#endif
#if ECAL_CORE_SUBSCRIBER
#include "pubsub/ecal_subgate.h"
#endif

#include <memory>

namespace eCAL
{
  class CGlobals
  {
  public:
    CGlobals();
    ~CGlobals();

    int Initialize    ( unsigned int components_, std::vector<std::string>* config_keys_ = nullptr);
    int IsInitialized ( unsigned int component_  );

    unsigned int GetComponents() const { return(components); };

    int Finalize(unsigned int components_);

    const std::unique_ptr<CConfig>&                                       config()                 { return config_instance; };
    const std::unique_ptr<CLog>&                                          log()                    { return log_instance; };
#if ECAL_CORE_TIMEPLUGIN
    const std::unique_ptr<CTimeGate>&                                     timegate()               { return timegate_instance; };
#endif
#if ECAL_CORE_SUBSCRIBER
    const std::unique_ptr<CSubGate>&                                      subgate()                { return subgate_instance; };
#endif
#if ECAL_CORE_PUBLISHER
    const std::unique_ptr<CPubGate>&                                      pubgate()                { return pubgate_instance; };
#endif
#if ECAL_CORE_REGISTRATION
    const std::unique_ptr<CRegistrationProvider>&                         registration_provider()  { return registration_provider_instance; };
    const std::unique_ptr<CRegistrationReceiver>&                         registration_receiver()  { return registration_receiver_instance; };
#endif

  private:
    bool                                                                  initialized;
    unsigned int                                                          components;
    std::unique_ptr<CConfig>                                              config_instance;
    std::unique_ptr<CLog>                                                 log_instance;
#if ECAL_CORE_TIMEPLUGIN
    std::unique_ptr<CTimeGate>                                            timegate_instance;
#endif
#if ECAL_CORE_SUBSCRIBER
    std::unique_ptr<CSubGate>                                             subgate_instance;
#endif
#if ECAL_CORE_PUBLISHER
    std::unique_ptr<CPubGate>                                             pubgate_instance;
#endif
#if ECAL_CORE_REGISTRATION
    std::unique_ptr<CRegistrationProvider>                                registration_provider_instance;
    std::unique_ptr<CRegistrationReceiver>                                registration_receiver_instance;
#endif
  };
}
