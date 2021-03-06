// Copyright 2016 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_INSPECTOR_V8SCHEMAAGENTIMPL_H_
#define V8_INSPECTOR_V8SCHEMAAGENTIMPL_H_

#include "src/inspector/Allocator.h"
#include "src/inspector/protocol/Forward.h"
#include "src/inspector/protocol/Schema.h"

namespace v8_inspector {

class V8InspectorSessionImpl;

using protocol::ErrorString;

class V8SchemaAgentImpl : public protocol::Schema::Backend {
  V8_INSPECTOR_DISALLOW_COPY(V8SchemaAgentImpl);

 public:
  V8SchemaAgentImpl(V8InspectorSessionImpl*, protocol::FrontendChannel*,
                    protocol::DictionaryValue* state);
  ~V8SchemaAgentImpl() override;

  void getDomains(
      ErrorString*,
      std::unique_ptr<protocol::Array<protocol::Schema::Domain>>*) override;

 private:
  V8InspectorSessionImpl* m_session;
  protocol::Schema::Frontend m_frontend;
};

}  // namespace v8_inspector

#endif  // V8_INSPECTOR_V8SCHEMAAGENTIMPL_H_
