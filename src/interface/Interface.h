/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef INTERFACE_INTERFACE_H_
#define INTERFACE_INTERFACE_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>
#include <tuple>
#include <vector>

#include "architecture/PortedDevice.h"
#include "event/Component.h"
#include "types/CreditReceiver.h"
#include "types/CreditSender.h"
#include "types/FlitReceiver.h"
#include "types/FlitSender.h"
#include "types/Message.h"
#include "types/MessageReceiver.h"
#include "network/Channel.h"

class PacketReassembler;
class MessageReassembler;

class Interface : public Component, public PortedDevice, public FlitSender,
                  public FlitReceiver, public CreditSender,
                  public CreditReceiver, public MessageReceiver {
 public:
  Interface(const std::string& _name, const Component* _parent, u32 _id,
            const std::vector<u32>& _address, u32 _numVcs,
            const std::vector<std::tuple<u32, u32> >& _trafficClassVcs,
            Json::Value _settings);
  virtual ~Interface();

  void setMessageReceiver(MessageReceiver* _receiver);
  MessageReceiver* messageReceiver() const;

 protected:
  const std::vector<std::tuple<u32, u32> > trafficClassVcs_;

 private:
  MessageReceiver* messageReceiver_;
  std::vector<PacketReassembler*> packetReassemblers_;
  MessageReassembler* messageReassembler_;
};

#endif  // INTERFACE_INTERFACE_H_
