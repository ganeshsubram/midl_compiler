#!/usr/bin/env python3

import yaml

def generate_cpp_enum(enum_name, values, underlying_type):
    code = f"    enum class {enum_name} : {underlying_type} {{\n"

    for value in values:
        code += f"        {value['name']} = {value['value']},\n"

    code += "    };\n"

    return code

def generate_cpp_struct(struct_name, fields):
    code = f"struct {struct_name} {{\n"

    for field in fields:
        field_name = field['name']
        field_type = field['type']
        is_big_endian = field.get('big_endian', False)

        is_enum = False
        if isinstance(field_type, dict) and 'enum' in field_type:
            is_enum = True
            enum_name = field_type['enum']['name']
            enum_values = field_type['enum']['values']
            underlying_type = field_type['enum'].get('underlying_type', 'int')
            if underlying_type.endswith(f"_t"):
                # e.g. int32_t, prepend with std so we don't need to do 'using namespace std'
                #  in the header (we're not savages).
                underlying_type = f"std::" + underlying_type

            code += generate_cpp_enum(enum_name, enum_values, underlying_type)
            field_type = enum_name
        elif field_type.endswith(f"_t"):
            # e.g. int32_t, prepend with std so we don't need to do 'using namespace std'
            #  in the header (we're not savages).
            field_type = f"std::" + field_type

        code += f"    {field_type} {field_name};\n"

        return_field = f"        return {field_name};\n"
        return_swapped_field = f"        return __builtin_bswap32({field_name});\n"
        return_static_casted_swapped_field = f"        return static_cast<{field_type}>(__builtin_bswap32({field_name}));\n"

        # Default getter (little endian with endianness swap if big endian)
        code += f"    {field_type} get_{field_name}() const {{\n"
        if is_big_endian:
            if is_enum == False:
                code += return_swapped_field
            else:
                code += return_static_casted_swapped_field
        else:
            code += return_field
        code += "    }\n"

        # Big endian getter
        code += f"    {field_type} get_{field_name}_big_endian() const {{\n"
        if is_big_endian:
            code += return_field
        else:
            if is_enum == False:
                code += return_swapped_field
            else:
                code += return_static_casted_swapped_field
        code += "    }\n"

        # Little endian getter
        code += f"    {field_type} get_{field_name}_little_endian() const {{\n"
        if is_big_endian:
            if is_enum == False:
                code += return_swapped_field
            else:
                code += return_static_casted_swapped_field
        else:
            code += return_field
        code += "    }\n"

    code += "};\n"

    return code

def generate_cpp_code(yaml_file):
    with open(yaml_file, 'r') as file:
        data = yaml.safe_load(file)

    code = f"\n#include <cstdint>\n\n"
    for namespace_data in data:
        namespace = namespace_data.get('namespace', "")
        messages = namespace_data['messages']

        code += f"namespace {namespace} {{\n\n" if namespace else ""
        for message in messages:
            struct_name = message['name']
            fields = message['fields']

            code += "#pragma pack(push, 1)\n"
            code += generate_cpp_struct(struct_name, fields)
            code += "#pragma pack(pop)\n\n"

        code += f"}}  // namespace {namespace}\n\n" if namespace else ""

    return code

def generate_cpp_file(yaml_file, output_file):
    cpp_code = generate_cpp_code(yaml_file)
    with open(output_file, 'w') as file:
        file.write(cpp_code)

# Example usage:
generate_cpp_file('messages.yml', 'messages.hh')
