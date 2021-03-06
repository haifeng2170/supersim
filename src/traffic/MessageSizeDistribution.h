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
#ifndef TRAFFIC_MESSAGESIZEDISTRIBUTION_H_
#define TRAFFIC_MESSAGESIZEDISTRIBUTION_H_

#include <prim/prim.h>

#include <string>

#include "event/Component.h"
#include "types/Message.h"

class MessageSizeDistribution : public Component {
 public:
  MessageSizeDistribution(const std::string& _name, const Component* _parent);
  virtual ~MessageSizeDistribution();

  // bounds must be defined
  virtual u32 minMessageSize() const = 0;
  virtual u32 maxMessageSize() const = 0;

  // generates a new message size from scratch
  virtual u32 nextMessageSize() = 0;

  // generates a message size based from a prior message
  virtual u32 nextMessageSize(const Message* _msg) = 0;
};

#endif  // TRAFFIC_MESSAGESIZEDISTRIBUTION_H_
