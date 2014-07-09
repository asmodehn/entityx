#pragma once

#define ENTITYX_MAX_COMPONENTS 64
/* #undef ENTITYX_HAVE_BOOST_PYTHON */
/* #undef ENTITYX_INSTALLED_PYTHON_PACKAGE_DIR */
/* #undef ENTITYX_NEED_GET_POINTER_SHARED_PTR_SPECIALIZATION */

#include <stdint.h>
#include "entityx/config.h"

namespace entityx {

static const uint64_t MAX_COMPONENTS = ENTITYX_MAX_COMPONENTS;

}  // namespace entityx


// Which shared_ptr implementation should we use?
#include <memory>
// for std::forward()
#include <utility>

namespace entityx {

template <typename T>
using ptr = std::shared_ptr<T>;
template <typename T>
using weak_ptr = std::weak_ptr<T>;
template <typename T, typename U>
ptr<U> static_pointer_cast(const ptr<T> &ptr) {
  return std::static_pointer_cast<U>(ptr);
}
template <typename T>
using enable_shared_from_this = std::enable_shared_from_this<T>;

}  // namespace entityx

namespace entityx {

template <typename T, typename... Args>
ptr<T> make_ptr(Args&&... args) {
    return ptr<T>(::new T(std::forward<Args>(args)...));
}

template <typename T>
bool operator == (const weak_ptr<T> &a, const weak_ptr<T> &b) {
  return a.lock() == b.lock();
}

template <typename T>
int use_count(const ptr<T> &ptr) {
  return ptr.use_count();
}

}  // namespace entityx
