
#pragma once

#include <cstdint>

namespace examples::messages {

#pragma pack(push, 1)
///
/// @brief This is a test message in examples::messages.
///
struct ExampleMsg {

    ///
    /// @brief This is the first field of ExampleMsg
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
    /// @brief Returns the value of the packed size of ExampleMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(ExampleMsg);
    }

    ///
    /// @brief This is the ThirdFieldEnum description
    ///
    enum ThirdFieldEnum : int {

        /// @brief This is the FirstValueName description
        FirstValueName = 0,

        /// @brief SecondValueName (0)
        SecondValueName = 1,

        /// @brief ThirdValueName (1)
        ThirdValueName = 2,
    };
    ///
    /// @brief This is the third_field description.
    ///
    enum third_field;
    ///
    /// @brief Returns the value of third_field (enum).
    ///
    ThirdFieldEnum get_third_field() const {
        return third_field;
    ///
    /// @brief Returns the value of third_field (enum) in Big Endian.
    ///
    ThirdFieldEnum get_third_field_big_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(static_cast<uint32_t>(third_field)));
    }
    ///
    /// @brief Returns the value of third_field (enum) in Little Endian.
    ///
    ThirdFieldEnum get_third_field_little_endian() const {
        return third_field;
    }

    ///
    /// @brief Returns the value of the packed size of ExampleMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(ExampleMsg);
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
///
/// @brief Example2Msg
///
struct Example2Msg {

    ///
    /// @brief first_field (uint8_t)
    ///
    std::uint8_t first_field;

    ///
    /// @brief Returns the value of first_field (std::uint8_t).
    ///
    std::uint8_t get_first_field() const {
        return first_field;
    }
    ///
    /// @brief Returns the value of first_field (std::uint8_t) in Big Endian.
    ///
    std::uint8_t get_first_field_big_endian() const {
        return __builtin_bswap32(first_field);
    }
    ///
    /// @brief Returns the value of first_field (std::uint8_t) in Little Endian.
    ///
    std::uint8_t get_first_field_little_endian() const {
        return first_field;
    }

    ///
    /// @brief Returns the value of the packed size of Example2Msg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(Example2Msg);
    }

    ///
    /// @brief second_field (int64_t)
    ///
    std::int64_t second_field;

    ///
    /// @brief Returns the value of second_field (std::int64_t).
    ///
    std::int64_t get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (std::int64_t) in Big Endian.
    ///
    std::int64_t get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (std::int64_t) in Little Endian.
    ///
    std::int64_t get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of Example2Msg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(Example2Msg);
    }

    ///
    /// @brief third_field (float)
    ///
    float third_field;

    ///
    /// @brief Returns the value of third_field (float).
    ///
    float get_third_field() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (float) in Big Endian.
    ///
    float get_third_field_big_endian() const {
        return __builtin_bswap32(third_field);
    }
    ///
    /// @brief Returns the value of third_field (float) in Little Endian.
    ///
    float get_third_field_little_endian() const {
        return third_field;
    }

    ///
    /// @brief Returns the value of the packed size of Example2Msg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(Example2Msg);
    }
};
#pragma pack(pop)

}  // namespace examples::messages

namespace examples::different::messages {

#pragma pack(push, 1)
///
/// @brief ExampleMsg
///
struct ExampleMsg {

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
    /// @brief Returns the value of the packed size of ExampleMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(ExampleMsg);
    }

    ///
    /// @brief second_field (uint16_t)
    ///
    std::uint16_t second_field;

    ///
    /// @brief Returns the value of second_field (std::uint16_t).
    ///
    std::uint16_t get_second_field() const {
        return second_field;
    }
    ///
    /// @brief Returns the value of second_field (std::uint16_t) in Big Endian.
    ///
    std::uint16_t get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    ///
    /// @brief Returns the value of second_field (std::uint16_t) in Little Endian.
    ///
    std::uint16_t get_second_field_little_endian() const {
        return second_field;
    }

    ///
    /// @brief Returns the value of the packed size of ExampleMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(ExampleMsg);
    }

    ///
    /// @brief third_field (int8_t)
    ///
    std::int8_t third_field;

    ///
    /// @brief Returns the value of third_field (std::int8_t).
    ///
    std::int8_t get_third_field() const {
        return third_field;
    }
    ///
    /// @brief Returns the value of third_field (std::int8_t) in Big Endian.
    ///
    std::int8_t get_third_field_big_endian() const {
        return __builtin_bswap32(third_field);
    }
    ///
    /// @brief Returns the value of third_field (std::int8_t) in Little Endian.
    ///
    std::int8_t get_third_field_little_endian() const {
        return third_field;
    }

    ///
    /// @brief Returns the value of the packed size of ExampleMsg in bytes.
    ///
    static constexpr std::size_t size() {
        return sizeof(ExampleMsg);
    }
};
#pragma pack(pop)

}  // namespace examples::different::messages

