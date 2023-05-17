
#include <cstdint>

namespace glyd::examples::namespace_one {

#pragma pack(push, 1)
struct MyFirstMsg {
    std::uint32_t first_field;
    std::uint32_t get_first_field() const {
        return __builtin_bswap32(first_field);
    }
    std::uint32_t get_first_field_big_endian() const {
        return first_field;
    }
    std::uint32_t get_first_field_little_endian() const {
        return __builtin_bswap32(first_field);
    }
    float second_field;
    float get_second_field() const {
        return second_field;
    }
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    float get_second_field_little_endian() const {
        return second_field;
    }
    enum class ThirdFieldEnum : std::uint32_t {
        FirstValueName = 0,
        SecondValueName = 1,
        ThirdValueName = 2,
    };
    ThirdFieldEnum third_field;
    ThirdFieldEnum get_third_field() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
    ThirdFieldEnum get_third_field_big_endian() const {
        return third_field;
    }
    ThirdFieldEnum get_third_field_little_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
struct MySecondMsg {
    std::uint32_t first_field;
    std::uint32_t get_first_field() const {
        return first_field;
    }
    std::uint32_t get_first_field_big_endian() const {
        return __builtin_bswap32(first_field);
    }
    std::uint32_t get_first_field_little_endian() const {
        return first_field;
    }
    float second_field;
    float get_second_field() const {
        return second_field;
    }
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    float get_second_field_little_endian() const {
        return second_field;
    }
    enum class ThirdFieldEnum : int {
        FirstValueName = 0,
        SecondValueName = 1,
    };
    ThirdFieldEnum third_field;
    ThirdFieldEnum get_third_field() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
    ThirdFieldEnum get_third_field_big_endian() const {
        return third_field;
    }
    ThirdFieldEnum get_third_field_little_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
};
#pragma pack(pop)

}  // namespace glyd::examples::namespace_one

namespace glyd::examples::namespace_two {

#pragma pack(push, 1)
struct MyFirstMsg {
    std::uint32_t first_field;
    std::uint32_t get_first_field() const {
        return __builtin_bswap32(first_field);
    }
    std::uint32_t get_first_field_big_endian() const {
        return first_field;
    }
    std::uint32_t get_first_field_little_endian() const {
        return __builtin_bswap32(first_field);
    }
    float second_field;
    float get_second_field() const {
        return second_field;
    }
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    float get_second_field_little_endian() const {
        return second_field;
    }
    enum class ThirdFieldEnum : std::uint8_t {
        FirstValueName = 0,
        SecondValueName = 1,
        ThirdValueName = 2,
    };
    ThirdFieldEnum third_field;
    ThirdFieldEnum get_third_field() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
    ThirdFieldEnum get_third_field_big_endian() const {
        return third_field;
    }
    ThirdFieldEnum get_third_field_little_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
};
#pragma pack(pop)

#pragma pack(push, 1)
struct MySecondMsg {
    std::uint32_t first_field;
    std::uint32_t get_first_field() const {
        return first_field;
    }
    std::uint32_t get_first_field_big_endian() const {
        return __builtin_bswap32(first_field);
    }
    std::uint32_t get_first_field_little_endian() const {
        return first_field;
    }
    float second_field;
    float get_second_field() const {
        return second_field;
    }
    float get_second_field_big_endian() const {
        return __builtin_bswap32(second_field);
    }
    float get_second_field_little_endian() const {
        return second_field;
    }
    enum class ThirdFieldEnum : int {
        FirstValueName = 0,
        SecondValueName = 1,
    };
    ThirdFieldEnum third_field;
    ThirdFieldEnum get_third_field() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
    ThirdFieldEnum get_third_field_big_endian() const {
        return third_field;
    }
    ThirdFieldEnum get_third_field_little_endian() const {
        return static_cast<ThirdFieldEnum>(__builtin_bswap32(third_field));
    }
};
#pragma pack(pop)

}  // namespace glyd::examples::namespace_two

