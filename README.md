# MIDL Compiler (C++)

## Dependencies

Requires `libyaml` to load the initial YAML config, which can easily be installed with:

```bash
sudo apt-get install libyaml-cpp-dev
```

## Build

First, make a build directory and enter build directory:

```bash
mkdir build && cd build
```

First-time only, run cmake in the `build` directory:

```bash
cmake ..
```

Then run make to build and rebuild:

```bash
make
```

You should see `midl_compiler` executable output in the build directory.

## Usage

```bash
./midl_compiler ../messages.yml
```

Will generate a `messages.hh` adjacent `messages.yml` (up one directory from `build` since that's where the input `messages.yml` file is).

The resulting header file will contain:

- The packed-struct definitions for all messages

Each struct definition will contain:

- Getters for each field, including explicit getters for both little-endian and big-endian
- A constexpr size() method

## Example

Sample input YAML:

```YAML
---
- namespace: examples::namespace_one
  messages:
    - name: MyFirstMsg
      description: MyFirstMsg is a cool message.
      fields:
        - name: first_field   # Bytes 0-3
          description: This is the first field of MyFirstMsg message.
          type: uint32_t
          big_endian: true    # Defaults to false (little-endian)

        - name: second_field  # Bytes 4-7
          type: float

        - name: third_field   # Byte 8
          big_endian: true
          type: enum
          enum:
              name: ThirdFieldEnum
              description: This is the Enum description
              underlying_type: uint8_t  # Defaults to int
              values:
                - name: FirstValueName
                  description: This is the FirstValueName description
                  value: 0
                - name: SecondValueName
                  value: 1
                - name: ThirdValueName
                  value: 2

    - name: MySecondMsg
      fields:
        - name: first_field
          type: uint32_t

        - name: second_field
          type: float

        - name: third_field
          type: float
          big_endian: true

- namespace: examples::namespace_two
  messages:
    - name: MyFirstMsg
      fields:
        - name: first_field   # Bytes 0-3
          type: uint32_t
          big_endian: true    # Defaults to false (little-endian)

        - name: second_field  # Bytes 4-7
          type: float

        - name: third_field   # Byte 8
          type: int32_t
          big_endian: true

    - name: MySecondMsg
      fields:
        - name: first_field
          type: uint32_t

        - name: second_field
          type: float

        - name: third_field
          type: double
          big_endian: true

```

Example generated header:

```cpp

#pragma once

#include <cstdint>

namespace examples::namespace_one {

#pragma pack(push, 1)
///
/// @brief MyFirstMsg is a cool message.
///
struct MyFirstMsg {

    ///
    /// @brief This is the first field of MyFirstMsg message.
    ///
    std::uint32_t first_field;

    ///
    /// @brief Returns the value of first_field (std::uint32_t).
    ///
    std::uint32_t get_first_field() const {
        return __builtin_bswap32(first_field);
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Big Endian.
    ///
    std::uint32_t get_first_field_big_endian() const {
        return first_field;
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Little Endian.
    ///
    std::uint32_t get_first_field_little_endian() const {
        return __builtin_bswap32(first_field);
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }

    ///
    /// @brief second_field (float)
    ///
    float second_field;

    ///
    /// @brief Returns the value of second_field (float).
    ///
    float get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (float) in Big Endian.
    ///
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (float) in Little Endian.
    ///
    float get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }

    ///
    /// @brief This is the Enum description
    ///
    enum ThirdFieldEnum : std::uint8_t {

        /// @brief This is the FirstValueName description
        FirstValueName = 0,

        /// @brief SecondValueName (0)
        SecondValueName = 1,

        /// @brief ThirdValueName (1)
        ThirdValueName = 2,
    };
    ///
    /// @brief third_field (enum)
    ///
    enum third_field;
    ///
    /// @brief Returns the value of third_field (enum).
    ///
    ThirdFieldEnum get_third_field() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(static_cast<uint32_t>(third_field)));
    ///
    /// @brief Returns the value of third_field (enum) in Big Endian.
    ///
    ThirdFieldEnum get_third_field_big_endian() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (enum) in Little Endian.
    ///
    ThirdFieldEnum get_third_field_little_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(static_cast<uint32_t>(third_field)));
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
///
/// @brief MySecondMsg
///
struct MySecondMsg {

    ///
    /// @brief first_field (uint32_t)
    ///
    std::uint32_t first_field;

    ///
    /// @brief Returns the value of first_field (std::uint32_t).
    ///
    std::uint32_t get_first_field() const {
        return first_field;
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Big Endian.
    ///
    std::uint32_t get_first_field_big_endian() const {
        return __builtin_bswap32(first_field);
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Little Endian.
    ///
    std::uint32_t get_first_field_little_endian() const {
        return first_field;
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }

    ///
    /// @brief second_field (float)
    ///
    float second_field;

    ///
    /// @brief Returns the value of second_field (float).
    ///
    float get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (float) in Big Endian.
    ///
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (float) in Little Endian.
    ///
    float get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }

    ///
    /// @brief third_field (float)
    ///
    float third_field;

    ///
    /// @brief Returns the value of third_field (float).
    ///
    float get_third_field() const {
        return __builtin_bswap32(third_field);
    }
    ///
    /// @brief Returns the value of third_field (float) in Big Endian.
    ///
    float get_third_field_big_endian() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (float) in Little Endian.
    ///
    float get_third_field_little_endian() const {
        return __builtin_bswap32(third_field);
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }
};
#pragma pack(pop)

}  // namespace examples::namespace_one

namespace examples::namespace_two {

#pragma pack(push, 1)
///
/// @brief MyFirstMsg
///
struct MyFirstMsg {

    ///
    /// @brief first_field (uint32_t)
    ///
    std::uint32_t first_field;

    ///
    /// @brief Returns the value of first_field (std::uint32_t).
    ///
    std::uint32_t get_first_field() const {
        return __builtin_bswap32(first_field);
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Big Endian.
    ///
    std::uint32_t get_first_field_big_endian() const {
        return first_field;
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Little Endian.
    ///
    std::uint32_t get_first_field_little_endian() const {
        return __builtin_bswap32(first_field);
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }

    ///
    /// @brief second_field (float)
    ///
    float second_field;

    ///
    /// @brief Returns the value of second_field (float).
    ///
    float get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (float) in Big Endian.
    ///
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (float) in Little Endian.
    ///
    float get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }

    ///
    /// @brief third_field (int32_t)
    ///
    std::int32_t third_field;

    ///
    /// @brief Returns the value of third_field (std::int32_t).
    ///
    std::int32_t get_third_field() const {
        return __builtin_bswap32(third_field);
    }
    ///
    /// @brief Returns the value of third_field (std::int32_t) in Big Endian.
    ///
    std::int32_t get_third_field_big_endian() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (std::int32_t) in Little Endian.
    ///
    std::int32_t get_third_field_little_endian() const {
        return __builtin_bswap32(third_field);
    }

    ///
    /// @brief Returns the value of the packed size of MyFirstMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MyFirstMsg);
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
///
/// @brief MySecondMsg
///
struct MySecondMsg {

    ///
    /// @brief first_field (uint32_t)
    ///
    std::uint32_t first_field;

    ///
    /// @brief Returns the value of first_field (std::uint32_t).
    ///
    std::uint32_t get_first_field() const {
        return first_field;
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Big Endian.
    ///
    std::uint32_t get_first_field_big_endian() const {
        return __builtin_bswap32(first_field);
    }
    ///
    /// @brief Returns the value of first_field (std::uint32_t) in Little Endian.
    ///
    std::uint32_t get_first_field_little_endian() const {
        return first_field;
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }

    ///
    /// @brief second_field (float)
    ///
    float second_field;

    ///
    /// @brief Returns the value of second_field (float).
    ///
    float get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (float) in Big Endian.
    ///
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (float) in Little Endian.
    ///
    float get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }

    ///
    /// @brief third_field (double)
    ///
    double third_field;

    ///
    /// @brief Returns the value of third_field (double).
    ///
    double get_third_field() const {
        return __builtin_bswap32(third_field);
    }
    ///
    /// @brief Returns the value of third_field (double) in Big Endian.
    ///
    double get_third_field_big_endian() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (double) in Little Endian.
    ///
    double get_third_field_little_endian() const {
        return __builtin_bswap32(third_field);
    }

    ///
    /// @brief Returns the value of the packed size of MySecondMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(MySecondMsg);
    }
};
#pragma pack(pop)

}  // namespace examples::namespace_two

```
