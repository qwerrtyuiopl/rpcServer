// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: registrationMessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_registrationMessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_registrationMessage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Ip.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_registrationMessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_registrationMessage_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_registrationMessage_2eproto;
namespace rpc {
class RegistrationRequest;
struct RegistrationRequestDefaultTypeInternal;
extern RegistrationRequestDefaultTypeInternal _RegistrationRequest_default_instance_;
class RegistrationResponse;
struct RegistrationResponseDefaultTypeInternal;
extern RegistrationResponseDefaultTypeInternal _RegistrationResponse_default_instance_;
}  // namespace rpc
PROTOBUF_NAMESPACE_OPEN
template<> ::rpc::RegistrationRequest* Arena::CreateMaybeMessage<::rpc::RegistrationRequest>(Arena*);
template<> ::rpc::RegistrationResponse* Arena::CreateMaybeMessage<::rpc::RegistrationResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace rpc {

// ===================================================================

class RegistrationRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:rpc.RegistrationRequest) */ {
 public:
  inline RegistrationRequest() : RegistrationRequest(nullptr) {}
  ~RegistrationRequest() override;
  explicit PROTOBUF_CONSTEXPR RegistrationRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RegistrationRequest(const RegistrationRequest& from);
  RegistrationRequest(RegistrationRequest&& from) noexcept
    : RegistrationRequest() {
    *this = ::std::move(from);
  }

  inline RegistrationRequest& operator=(const RegistrationRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline RegistrationRequest& operator=(RegistrationRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RegistrationRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const RegistrationRequest* internal_default_instance() {
    return reinterpret_cast<const RegistrationRequest*>(
               &_RegistrationRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RegistrationRequest& a, RegistrationRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(RegistrationRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RegistrationRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RegistrationRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RegistrationRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RegistrationRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const RegistrationRequest& from) {
    RegistrationRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegistrationRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "rpc.RegistrationRequest";
  }
  protected:
  explicit RegistrationRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRequestedServiceFieldNumber = 1,
    kProvidedServiceFieldNumber = 2,
    kNginxIpFieldNumber = 3,
  };
  // repeated string requestedService = 1;
  int requestedservice_size() const;
  private:
  int _internal_requestedservice_size() const;
  public:
  void clear_requestedservice();
  const std::string& requestedservice(int index) const;
  std::string* mutable_requestedservice(int index);
  void set_requestedservice(int index, const std::string& value);
  void set_requestedservice(int index, std::string&& value);
  void set_requestedservice(int index, const char* value);
  void set_requestedservice(int index, const char* value, size_t size);
  std::string* add_requestedservice();
  void add_requestedservice(const std::string& value);
  void add_requestedservice(std::string&& value);
  void add_requestedservice(const char* value);
  void add_requestedservice(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& requestedservice() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_requestedservice();
  private:
  const std::string& _internal_requestedservice(int index) const;
  std::string* _internal_add_requestedservice();
  public:

  // repeated string providedService = 2;
  int providedservice_size() const;
  private:
  int _internal_providedservice_size() const;
  public:
  void clear_providedservice();
  const std::string& providedservice(int index) const;
  std::string* mutable_providedservice(int index);
  void set_providedservice(int index, const std::string& value);
  void set_providedservice(int index, std::string&& value);
  void set_providedservice(int index, const char* value);
  void set_providedservice(int index, const char* value, size_t size);
  std::string* add_providedservice();
  void add_providedservice(const std::string& value);
  void add_providedservice(std::string&& value);
  void add_providedservice(const char* value);
  void add_providedservice(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& providedservice() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_providedservice();
  private:
  const std::string& _internal_providedservice(int index) const;
  std::string* _internal_add_providedservice();
  public:

  // .rpc.Ip nginxIp = 3;
  bool has_nginxip() const;
  private:
  bool _internal_has_nginxip() const;
  public:
  void clear_nginxip();
  const ::rpc::Ip& nginxip() const;
  PROTOBUF_NODISCARD ::rpc::Ip* release_nginxip();
  ::rpc::Ip* mutable_nginxip();
  void set_allocated_nginxip(::rpc::Ip* nginxip);
  private:
  const ::rpc::Ip& _internal_nginxip() const;
  ::rpc::Ip* _internal_mutable_nginxip();
  public:
  void unsafe_arena_set_allocated_nginxip(
      ::rpc::Ip* nginxip);
  ::rpc::Ip* unsafe_arena_release_nginxip();

  // @@protoc_insertion_point(class_scope:rpc.RegistrationRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> requestedservice_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> providedservice_;
    ::rpc::Ip* nginxip_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_registrationMessage_2eproto;
};
// -------------------------------------------------------------------

class RegistrationResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:rpc.RegistrationResponse) */ {
 public:
  inline RegistrationResponse() : RegistrationResponse(nullptr) {}
  ~RegistrationResponse() override;
  explicit PROTOBUF_CONSTEXPR RegistrationResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  RegistrationResponse(const RegistrationResponse& from);
  RegistrationResponse(RegistrationResponse&& from) noexcept
    : RegistrationResponse() {
    *this = ::std::move(from);
  }

  inline RegistrationResponse& operator=(const RegistrationResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline RegistrationResponse& operator=(RegistrationResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const RegistrationResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const RegistrationResponse* internal_default_instance() {
    return reinterpret_cast<const RegistrationResponse*>(
               &_RegistrationResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(RegistrationResponse& a, RegistrationResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(RegistrationResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RegistrationResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  RegistrationResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<RegistrationResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const RegistrationResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const RegistrationResponse& from) {
    RegistrationResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegistrationResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "rpc.RegistrationResponse";
  }
  protected:
  explicit RegistrationResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIpFieldNumber = 1,
    kServiceFieldNumber = 2,
  };
  // repeated .rpc.Ip ip = 1;
  int ip_size() const;
  private:
  int _internal_ip_size() const;
  public:
  void clear_ip();
  ::rpc::Ip* mutable_ip(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::rpc::Ip >*
      mutable_ip();
  private:
  const ::rpc::Ip& _internal_ip(int index) const;
  ::rpc::Ip* _internal_add_ip();
  public:
  const ::rpc::Ip& ip(int index) const;
  ::rpc::Ip* add_ip();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::rpc::Ip >&
      ip() const;

  // repeated string service = 2;
  int service_size() const;
  private:
  int _internal_service_size() const;
  public:
  void clear_service();
  const std::string& service(int index) const;
  std::string* mutable_service(int index);
  void set_service(int index, const std::string& value);
  void set_service(int index, std::string&& value);
  void set_service(int index, const char* value);
  void set_service(int index, const char* value, size_t size);
  std::string* add_service();
  void add_service(const std::string& value);
  void add_service(std::string&& value);
  void add_service(const char* value);
  void add_service(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& service() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_service();
  private:
  const std::string& _internal_service(int index) const;
  std::string* _internal_add_service();
  public:

  // @@protoc_insertion_point(class_scope:rpc.RegistrationResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::rpc::Ip > ip_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> service_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_registrationMessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegistrationRequest

// repeated string requestedService = 1;
inline int RegistrationRequest::_internal_requestedservice_size() const {
  return _impl_.requestedservice_.size();
}
inline int RegistrationRequest::requestedservice_size() const {
  return _internal_requestedservice_size();
}
inline void RegistrationRequest::clear_requestedservice() {
  _impl_.requestedservice_.Clear();
}
inline std::string* RegistrationRequest::add_requestedservice() {
  std::string* _s = _internal_add_requestedservice();
  // @@protoc_insertion_point(field_add_mutable:rpc.RegistrationRequest.requestedService)
  return _s;
}
inline const std::string& RegistrationRequest::_internal_requestedservice(int index) const {
  return _impl_.requestedservice_.Get(index);
}
inline const std::string& RegistrationRequest::requestedservice(int index) const {
  // @@protoc_insertion_point(field_get:rpc.RegistrationRequest.requestedService)
  return _internal_requestedservice(index);
}
inline std::string* RegistrationRequest::mutable_requestedservice(int index) {
  // @@protoc_insertion_point(field_mutable:rpc.RegistrationRequest.requestedService)
  return _impl_.requestedservice_.Mutable(index);
}
inline void RegistrationRequest::set_requestedservice(int index, const std::string& value) {
  _impl_.requestedservice_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::set_requestedservice(int index, std::string&& value) {
  _impl_.requestedservice_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::set_requestedservice(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.requestedservice_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::set_requestedservice(int index, const char* value, size_t size) {
  _impl_.requestedservice_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rpc.RegistrationRequest.requestedService)
}
inline std::string* RegistrationRequest::_internal_add_requestedservice() {
  return _impl_.requestedservice_.Add();
}
inline void RegistrationRequest::add_requestedservice(const std::string& value) {
  _impl_.requestedservice_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::add_requestedservice(std::string&& value) {
  _impl_.requestedservice_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::add_requestedservice(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.requestedservice_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:rpc.RegistrationRequest.requestedService)
}
inline void RegistrationRequest::add_requestedservice(const char* value, size_t size) {
  _impl_.requestedservice_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:rpc.RegistrationRequest.requestedService)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
RegistrationRequest::requestedservice() const {
  // @@protoc_insertion_point(field_list:rpc.RegistrationRequest.requestedService)
  return _impl_.requestedservice_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
RegistrationRequest::mutable_requestedservice() {
  // @@protoc_insertion_point(field_mutable_list:rpc.RegistrationRequest.requestedService)
  return &_impl_.requestedservice_;
}

// repeated string providedService = 2;
inline int RegistrationRequest::_internal_providedservice_size() const {
  return _impl_.providedservice_.size();
}
inline int RegistrationRequest::providedservice_size() const {
  return _internal_providedservice_size();
}
inline void RegistrationRequest::clear_providedservice() {
  _impl_.providedservice_.Clear();
}
inline std::string* RegistrationRequest::add_providedservice() {
  std::string* _s = _internal_add_providedservice();
  // @@protoc_insertion_point(field_add_mutable:rpc.RegistrationRequest.providedService)
  return _s;
}
inline const std::string& RegistrationRequest::_internal_providedservice(int index) const {
  return _impl_.providedservice_.Get(index);
}
inline const std::string& RegistrationRequest::providedservice(int index) const {
  // @@protoc_insertion_point(field_get:rpc.RegistrationRequest.providedService)
  return _internal_providedservice(index);
}
inline std::string* RegistrationRequest::mutable_providedservice(int index) {
  // @@protoc_insertion_point(field_mutable:rpc.RegistrationRequest.providedService)
  return _impl_.providedservice_.Mutable(index);
}
inline void RegistrationRequest::set_providedservice(int index, const std::string& value) {
  _impl_.providedservice_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::set_providedservice(int index, std::string&& value) {
  _impl_.providedservice_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::set_providedservice(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.providedservice_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::set_providedservice(int index, const char* value, size_t size) {
  _impl_.providedservice_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rpc.RegistrationRequest.providedService)
}
inline std::string* RegistrationRequest::_internal_add_providedservice() {
  return _impl_.providedservice_.Add();
}
inline void RegistrationRequest::add_providedservice(const std::string& value) {
  _impl_.providedservice_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::add_providedservice(std::string&& value) {
  _impl_.providedservice_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::add_providedservice(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.providedservice_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:rpc.RegistrationRequest.providedService)
}
inline void RegistrationRequest::add_providedservice(const char* value, size_t size) {
  _impl_.providedservice_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:rpc.RegistrationRequest.providedService)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
RegistrationRequest::providedservice() const {
  // @@protoc_insertion_point(field_list:rpc.RegistrationRequest.providedService)
  return _impl_.providedservice_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
RegistrationRequest::mutable_providedservice() {
  // @@protoc_insertion_point(field_mutable_list:rpc.RegistrationRequest.providedService)
  return &_impl_.providedservice_;
}

// .rpc.Ip nginxIp = 3;
inline bool RegistrationRequest::_internal_has_nginxip() const {
  return this != internal_default_instance() && _impl_.nginxip_ != nullptr;
}
inline bool RegistrationRequest::has_nginxip() const {
  return _internal_has_nginxip();
}
inline const ::rpc::Ip& RegistrationRequest::_internal_nginxip() const {
  const ::rpc::Ip* p = _impl_.nginxip_;
  return p != nullptr ? *p : reinterpret_cast<const ::rpc::Ip&>(
      ::rpc::_Ip_default_instance_);
}
inline const ::rpc::Ip& RegistrationRequest::nginxip() const {
  // @@protoc_insertion_point(field_get:rpc.RegistrationRequest.nginxIp)
  return _internal_nginxip();
}
inline void RegistrationRequest::unsafe_arena_set_allocated_nginxip(
    ::rpc::Ip* nginxip) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.nginxip_);
  }
  _impl_.nginxip_ = nginxip;
  if (nginxip) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:rpc.RegistrationRequest.nginxIp)
}
inline ::rpc::Ip* RegistrationRequest::release_nginxip() {
  
  ::rpc::Ip* temp = _impl_.nginxip_;
  _impl_.nginxip_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::rpc::Ip* RegistrationRequest::unsafe_arena_release_nginxip() {
  // @@protoc_insertion_point(field_release:rpc.RegistrationRequest.nginxIp)
  
  ::rpc::Ip* temp = _impl_.nginxip_;
  _impl_.nginxip_ = nullptr;
  return temp;
}
inline ::rpc::Ip* RegistrationRequest::_internal_mutable_nginxip() {
  
  if (_impl_.nginxip_ == nullptr) {
    auto* p = CreateMaybeMessage<::rpc::Ip>(GetArenaForAllocation());
    _impl_.nginxip_ = p;
  }
  return _impl_.nginxip_;
}
inline ::rpc::Ip* RegistrationRequest::mutable_nginxip() {
  ::rpc::Ip* _msg = _internal_mutable_nginxip();
  // @@protoc_insertion_point(field_mutable:rpc.RegistrationRequest.nginxIp)
  return _msg;
}
inline void RegistrationRequest::set_allocated_nginxip(::rpc::Ip* nginxip) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.nginxip_);
  }
  if (nginxip) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(nginxip));
    if (message_arena != submessage_arena) {
      nginxip = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, nginxip, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.nginxip_ = nginxip;
  // @@protoc_insertion_point(field_set_allocated:rpc.RegistrationRequest.nginxIp)
}

// -------------------------------------------------------------------

// RegistrationResponse

// repeated .rpc.Ip ip = 1;
inline int RegistrationResponse::_internal_ip_size() const {
  return _impl_.ip_.size();
}
inline int RegistrationResponse::ip_size() const {
  return _internal_ip_size();
}
inline ::rpc::Ip* RegistrationResponse::mutable_ip(int index) {
  // @@protoc_insertion_point(field_mutable:rpc.RegistrationResponse.ip)
  return _impl_.ip_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::rpc::Ip >*
RegistrationResponse::mutable_ip() {
  // @@protoc_insertion_point(field_mutable_list:rpc.RegistrationResponse.ip)
  return &_impl_.ip_;
}
inline const ::rpc::Ip& RegistrationResponse::_internal_ip(int index) const {
  return _impl_.ip_.Get(index);
}
inline const ::rpc::Ip& RegistrationResponse::ip(int index) const {
  // @@protoc_insertion_point(field_get:rpc.RegistrationResponse.ip)
  return _internal_ip(index);
}
inline ::rpc::Ip* RegistrationResponse::_internal_add_ip() {
  return _impl_.ip_.Add();
}
inline ::rpc::Ip* RegistrationResponse::add_ip() {
  ::rpc::Ip* _add = _internal_add_ip();
  // @@protoc_insertion_point(field_add:rpc.RegistrationResponse.ip)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::rpc::Ip >&
RegistrationResponse::ip() const {
  // @@protoc_insertion_point(field_list:rpc.RegistrationResponse.ip)
  return _impl_.ip_;
}

// repeated string service = 2;
inline int RegistrationResponse::_internal_service_size() const {
  return _impl_.service_.size();
}
inline int RegistrationResponse::service_size() const {
  return _internal_service_size();
}
inline void RegistrationResponse::clear_service() {
  _impl_.service_.Clear();
}
inline std::string* RegistrationResponse::add_service() {
  std::string* _s = _internal_add_service();
  // @@protoc_insertion_point(field_add_mutable:rpc.RegistrationResponse.service)
  return _s;
}
inline const std::string& RegistrationResponse::_internal_service(int index) const {
  return _impl_.service_.Get(index);
}
inline const std::string& RegistrationResponse::service(int index) const {
  // @@protoc_insertion_point(field_get:rpc.RegistrationResponse.service)
  return _internal_service(index);
}
inline std::string* RegistrationResponse::mutable_service(int index) {
  // @@protoc_insertion_point(field_mutable:rpc.RegistrationResponse.service)
  return _impl_.service_.Mutable(index);
}
inline void RegistrationResponse::set_service(int index, const std::string& value) {
  _impl_.service_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::set_service(int index, std::string&& value) {
  _impl_.service_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::set_service(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.service_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::set_service(int index, const char* value, size_t size) {
  _impl_.service_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rpc.RegistrationResponse.service)
}
inline std::string* RegistrationResponse::_internal_add_service() {
  return _impl_.service_.Add();
}
inline void RegistrationResponse::add_service(const std::string& value) {
  _impl_.service_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::add_service(std::string&& value) {
  _impl_.service_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::add_service(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.service_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:rpc.RegistrationResponse.service)
}
inline void RegistrationResponse::add_service(const char* value, size_t size) {
  _impl_.service_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:rpc.RegistrationResponse.service)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
RegistrationResponse::service() const {
  // @@protoc_insertion_point(field_list:rpc.RegistrationResponse.service)
  return _impl_.service_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
RegistrationResponse::mutable_service() {
  // @@protoc_insertion_point(field_mutable_list:rpc.RegistrationResponse.service)
  return &_impl_.service_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace rpc

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_registrationMessage_2eproto
