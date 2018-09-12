/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBERTRON_DATA_FUSION_DATA_FUSION_H_
#define CYBERTRON_DATA_FUSION_DATA_FUSION_H_

#include <deque>
#include <memory>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <vector>

#include "cybertron/common/types.h"

namespace apollo {
namespace cybertron {
namespace data {
namespace fusion {

template <typename M0, typename M1 = NullType, typename M2 = NullType,
          typename M3 = NullType>
class DataFusion {
 public:
  virtual ~DataFusion() {}
  virtual bool Fusion(uint64_t* index, std::shared_ptr<M0>& m0,
                      std::shared_ptr<M1>& m1, std::shared_ptr<M2>& m2,
                      std::shared_ptr<M3>& m3) = 0;
};

template <typename M0, typename M1, typename M2>
class DataFusion<M0, M1, M2, NullType> {
 public:
  virtual ~DataFusion() {}

  virtual bool Fusion(uint64_t* index, std::shared_ptr<M0>& m0,
                      std::shared_ptr<M1>& m1, std::shared_ptr<M2>& m2) = 0;
};

template <typename M0, typename M1>
class DataFusion<M0, M1, NullType, NullType> {
 public:
  virtual ~DataFusion() {}

  virtual bool Fusion(uint64_t* index, std::shared_ptr<M0>& m0,
                      std::shared_ptr<M1>& m1) = 0;
};

}  // namespace fusion
}  // namespace data
}  // namespace cybertron
}  // namespace apollo

#endif  // CYBERTRON_DATA_FUSION_DATA_FUSION_H_