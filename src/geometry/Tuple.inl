namespace alg {

template <typename T>
inline Tuple2<T>::operator const T*() const noexcept {
  return tuple_;
}


template <typename T>
inline Tuple2<T>::operator T*() noexcept {
  return tuple_;
}


template <typename T>
inline const T& Tuple2<T>::operator[](int i) const noexcept {
  return tuple_[i];
}


template <typename T>
inline T& Tuple2<T>::operator[](int i) noexcept {
  return tuple_[i];
}


template <typename T>
inline Tuple2<T>& Tuple2<T>::operator=(const Tuple2& tuple) noexcept {
  for (int i = 0; i < 2; ++i) {
    tuple_[i] = tuple.tuple_[i];
  }

  return *this;
}


template <typename T>
bool Tuple2<T>::operator<(const Tuple2& other) const noexcept {
  for (int i = 0; i < 2; ++i) {
    if (tuple_[i] < other.tuple_[i]) {
      return true;
    }

    if (tuple_[i] > other.tuple_[i]) {
      return false;
    }
  }

  return false;
}


template <typename T>
bool Tuple2<T>::operator>(const Tuple2& other) const noexcept {
  for (int i = 0; i < 2; ++i) {
    if (tuple_[i] > other.tuple_[i]) {
      return true;
    }

    if (tuple_[i] < other.tuple_[i]) {
      return false;
    }
  }

  return false;
}


template <typename T>
inline bool Tuple2<T>::operator==(const Tuple2& other) const noexcept {
  for (int i = 0; i < 2; ++i) {
    if (tuple_[i] != other.tuple_[i]) {
      return false;
    }
  }
  
  return true;
}


template <typename T>
inline bool Tuple2<T>::operator!=(const Tuple2<T>& other) const noexcept {
  return !(*this).operator==(other);
}


template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Tuple2<T>& t) {
  out << t[0] << ", " << t[1];

  return out;
}

}  // namespace alg