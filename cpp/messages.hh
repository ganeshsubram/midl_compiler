
#pragma once

#include <cstdint>

namespace glyd::examples::namespace_one {

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

}  // namespace glyd::examples::namespace_one

namespace glyd::examples::namespace_two {

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

}  // namespace glyd::examples::namespace_two

