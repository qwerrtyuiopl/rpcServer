// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: updateNodeServiceArg.proto

#include "updateNodeServiceArg.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace rpc {
PROTOBUF_CONSTEXPR UpdateNodeServiceArg::UpdateNodeServiceArg(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.servicename_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.ip_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct UpdateNodeServiceArgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UpdateNodeServiceArgDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~UpdateNodeServiceArgDefaultTypeInternal() {}
  union {
    UpdateNodeServiceArg _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UpdateNodeServiceArgDefaultTypeInternal _UpdateNodeServiceArg_default_instance_;
}  // namespace rpc
static ::_pb::Metadata file_level_metadata_updateNodeServiceArg_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_updateNodeServiceArg_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_updateNodeServiceArg_2eproto = nullptr;

const uint32_t TableStruct_updateNodeServiceArg_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::rpc::UpdateNodeServiceArg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::rpc::UpdateNodeServiceArg, _impl_.ip_),
  PROTOBUF_FIELD_OFFSET(::rpc::UpdateNodeServiceArg, _impl_.servicename_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::rpc::UpdateNodeServiceArg)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::rpc::_UpdateNodeServiceArg_default_instance_._instance,
};

const char descriptor_table_protodef_updateNodeServiceArg_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\032updateNodeServiceArg.proto\022\003rpc\032\010Ip.pr"
  "oto\"@\n\024UpdateNodeServiceArg\022\023\n\002ip\030\001 \001(\0132"
  "\007.rpc.Ip\022\023\n\013serviceName\030\002 \001(\tb\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_updateNodeServiceArg_2eproto_deps[1] = {
  &::descriptor_table_Ip_2eproto,
};
static ::_pbi::once_flag descriptor_table_updateNodeServiceArg_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_updateNodeServiceArg_2eproto = {
    false, false, 117, descriptor_table_protodef_updateNodeServiceArg_2eproto,
    "updateNodeServiceArg.proto",
    &descriptor_table_updateNodeServiceArg_2eproto_once, descriptor_table_updateNodeServiceArg_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_updateNodeServiceArg_2eproto::offsets,
    file_level_metadata_updateNodeServiceArg_2eproto, file_level_enum_descriptors_updateNodeServiceArg_2eproto,
    file_level_service_descriptors_updateNodeServiceArg_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_updateNodeServiceArg_2eproto_getter() {
  return &descriptor_table_updateNodeServiceArg_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_updateNodeServiceArg_2eproto(&descriptor_table_updateNodeServiceArg_2eproto);
namespace rpc {

// ===================================================================

class UpdateNodeServiceArg::_Internal {
 public:
  static const ::rpc::Ip& ip(const UpdateNodeServiceArg* msg);
};

const ::rpc::Ip&
UpdateNodeServiceArg::_Internal::ip(const UpdateNodeServiceArg* msg) {
  return *msg->_impl_.ip_;
}
void UpdateNodeServiceArg::clear_ip() {
  if (GetArenaForAllocation() == nullptr && _impl_.ip_ != nullptr) {
    delete _impl_.ip_;
  }
  _impl_.ip_ = nullptr;
}
UpdateNodeServiceArg::UpdateNodeServiceArg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:rpc.UpdateNodeServiceArg)
}
UpdateNodeServiceArg::UpdateNodeServiceArg(const UpdateNodeServiceArg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  UpdateNodeServiceArg* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.servicename_){}
    , decltype(_impl_.ip_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.servicename_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.servicename_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_servicename().empty()) {
    _this->_impl_.servicename_.Set(from._internal_servicename(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_ip()) {
    _this->_impl_.ip_ = new ::rpc::Ip(*from._impl_.ip_);
  }
  // @@protoc_insertion_point(copy_constructor:rpc.UpdateNodeServiceArg)
}

inline void UpdateNodeServiceArg::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.servicename_){}
    , decltype(_impl_.ip_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.servicename_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.servicename_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

UpdateNodeServiceArg::~UpdateNodeServiceArg() {
  // @@protoc_insertion_point(destructor:rpc.UpdateNodeServiceArg)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void UpdateNodeServiceArg::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.servicename_.Destroy();
  if (this != internal_default_instance()) delete _impl_.ip_;
}

void UpdateNodeServiceArg::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void UpdateNodeServiceArg::Clear() {
// @@protoc_insertion_point(message_clear_start:rpc.UpdateNodeServiceArg)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.servicename_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.ip_ != nullptr) {
    delete _impl_.ip_;
  }
  _impl_.ip_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UpdateNodeServiceArg::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .rpc.Ip ip = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_ip(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string serviceName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_servicename();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "rpc.UpdateNodeServiceArg.serviceName"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* UpdateNodeServiceArg::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:rpc.UpdateNodeServiceArg)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .rpc.Ip ip = 1;
  if (this->_internal_has_ip()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::ip(this),
        _Internal::ip(this).GetCachedSize(), target, stream);
  }

  // string serviceName = 2;
  if (!this->_internal_servicename().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_servicename().data(), static_cast<int>(this->_internal_servicename().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "rpc.UpdateNodeServiceArg.serviceName");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_servicename(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rpc.UpdateNodeServiceArg)
  return target;
}

size_t UpdateNodeServiceArg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:rpc.UpdateNodeServiceArg)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string serviceName = 2;
  if (!this->_internal_servicename().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_servicename());
  }

  // .rpc.Ip ip = 1;
  if (this->_internal_has_ip()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.ip_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData UpdateNodeServiceArg::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    UpdateNodeServiceArg::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*UpdateNodeServiceArg::GetClassData() const { return &_class_data_; }


void UpdateNodeServiceArg::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<UpdateNodeServiceArg*>(&to_msg);
  auto& from = static_cast<const UpdateNodeServiceArg&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:rpc.UpdateNodeServiceArg)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_servicename().empty()) {
    _this->_internal_set_servicename(from._internal_servicename());
  }
  if (from._internal_has_ip()) {
    _this->_internal_mutable_ip()->::rpc::Ip::MergeFrom(
        from._internal_ip());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void UpdateNodeServiceArg::CopyFrom(const UpdateNodeServiceArg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:rpc.UpdateNodeServiceArg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UpdateNodeServiceArg::IsInitialized() const {
  return true;
}

void UpdateNodeServiceArg::InternalSwap(UpdateNodeServiceArg* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.servicename_, lhs_arena,
      &other->_impl_.servicename_, rhs_arena
  );
  swap(_impl_.ip_, other->_impl_.ip_);
}

::PROTOBUF_NAMESPACE_ID::Metadata UpdateNodeServiceArg::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_updateNodeServiceArg_2eproto_getter, &descriptor_table_updateNodeServiceArg_2eproto_once,
      file_level_metadata_updateNodeServiceArg_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace rpc
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::rpc::UpdateNodeServiceArg*
Arena::CreateMaybeMessage< ::rpc::UpdateNodeServiceArg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::rpc::UpdateNodeServiceArg >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
