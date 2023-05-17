
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

struct EnumValue {
  std::string name;
  std::string description;
  int value;

  std::string get_default_description() const {
    return name + " (" + std::to_string(this->value) + ")";
  };
};

struct Enum {
  std::string name;
  std::string description;
  std::string underlying_type;
  std::vector<EnumValue> values;

  std::string get_default_description() const {
    return name + " (" + this->underlying_type + ")";
  };
};

struct Field {
  std::string name;
  std::string description;
  std::string type;
  bool bigEndian;
  Enum enumType;

  std::string get_default_description() const {
    return name + " (" + this->type + ")";
  };
};

struct Message {
  std::string name;
  std::string description;
  std::vector<Field> fields;

  std::string get_default_description() const {
    return this->name;
  };
};

struct Namespace {
  std::string name;
  std::vector<Message> messages;
};

std::string generateEnumCode(const Enum &enumType) {
  std::string code;

  code += "    ///\n";
  code += "    /// @brief " + enumType.description + "\n";
  code += "    ///\n";
  code +=
      "    enum " + enumType.name + " : " + enumType.underlying_type + " {\n";
  for (const auto &value : enumType.values) {
    code += "\n";
    code += "        /// @brief " + value.description + "\n";
    code += "        " + value.name + " = " + std::to_string(value.value) + ",\n";
  }
  code += "    };\n";

  return code;
}

std::string generateStructCode(const Message& message) {
    std::string code;
    code += "#pragma pack(push, 1)\n";
    code += "///\n";
    code += "/// @brief " + message.description + "\n";
    code += "///\n";
    code += "struct " + message.name + " {\n";
    for (const auto& field : message.fields) {
        code += "\n";
        if (!field.enumType.name.empty()) {
            code += generateEnumCode(field.enumType);

            code += "    ///\n";
            code += "    /// @brief " + field.description + "\n";
            code += "    ///\n";
            code += "    " + field.type + " " + field.name + ";\n";

            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ").\n";
            code += "    ///\n";
            code += "    " + field.enumType.name + " get_" + field.name + "() const {\n";
            if (field.bigEndian) {
                code += "        return static_cast<" + field.enumType.name + ">(__builtin_bswap32(static_cast<uint32_t>(" + field.name + ")));\n";
            } else {
                code += "        return " + field.name + ";\n";
            }
            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ") in Big Endian.\n";
            code += "    ///\n";
            code += "    " + field.enumType.name + " get_" + field.name + "_big_endian() const {\n";
            if (field.bigEndian) {
                code += "        return " + field.name + ";\n";
            } else {
                code += "        return static_cast<" + field.enumType.name + ">(__builtin_bswap32(static_cast<uint32_t>(" + field.name + ")));\n";
            }
            code += "    }\n";
            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ") in Little Endian.\n";
            code += "    ///\n";
            code += "    " + field.enumType.name + " get_" + field.name + "_little_endian() const {\n";
            if (field.bigEndian) {
                code += "        return static_cast<" + field.enumType.name + ">(__builtin_bswap32(static_cast<uint32_t>(" + field.name + ")));\n";
            } else {
                code += "        return " + field.name + ";\n";
            }
            code += "    }\n";
        } else {
            code += "    ///\n";
            code += "    /// @brief " + field.description + "\n";
            code += "    ///\n";
            code += "    " + field.type + " " + field.name + ";\n";
            code += "\n";
            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ").\n";
            code += "    ///\n";
            code += "    " + field.type + " get_" + field.name + "() const {\n";
            if (field.bigEndian) {
                code += "        return __builtin_bswap32(" + field.name + ");\n";
            } else {
                code += "        return " + field.name + ";\n";
            }
            code += "    }\n";
            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ") in Big Endian.\n";
            code += "    ///\n";
            code += "    " + field.type + " get_" + field.name + "_big_endian() const {\n";
            if (field.bigEndian) {
                code += "        return " + field.name + ";\n";
            } else {
                code += "        return __builtin_bswap32(" + field.name + ");\n";
            }
            code += "    }\n";
            code += "    ///\n";
            code += "    /// @brief Returns the value of " + field.name + " (" + field.type + ") in Little Endian.\n";
            code += "    ///\n";
            code += "    " + field.type + " get_" + field.name + "_little_endian() const {\n";
            if (field.bigEndian) {
                code += "        return __builtin_bswap32(" + field.name + ");\n";
            } else {
                code += "        return " + field.name + ";\n";
            }
            code += "    }\n";
        }
        code += "\n";

        code += "    ///\n";
        code += "    /// @brief Returns the value of the packed size of " + message.name + " in bytes.\n";
        code += "    ///\n";
        code += "    static constexpr std::size_t size() {\n";
        code += "        return sizeof(" + message.name + ");\n";
        code += "    }\n";
    }
    code += "};\n";
    code += "#pragma pack(pop)\n\n";

    return code;
}

std::string generateCode(const std::vector<Namespace> &namespaces) {
  std::string code;

  code += "\n";
  code += "#pragma once\n\n";
  code += "#include <cstdint>\n\n";

  for (const auto &ns : namespaces) {
    if (!ns.name.empty()) {
      code += "namespace " + ns.name + " {\n\n";
    }

    for (const auto &message : ns.messages) {
      code += generateStructCode(message);
    }

    if (!ns.name.empty()) {
      code += "}  // namespace " + ns.name + "\n\n";
    }
  }

  return code;
}

void generateCppFile(const std::string &yamlFile,
                     const std::string &outputFile) {
  std::ifstream file(yamlFile);
  if (!file) {
    std::cerr << "Failed to open the YAML file.\n";
    return;
  }

  YAML::Node data = YAML::Load(file);

  std::vector<Namespace> namespaces;

  if (data.IsSequence()) {
    for (const auto &nsData : data) {
      Namespace ns;
      ns.name = nsData["namespace"].as<std::string>();

      for (const auto &msgData : nsData["messages"]) {
        Message msg;
        msg.name = msgData["name"].as<std::string>();
        if(msgData["description"]) {
          msg.description = msgData["description"].as<std::string>();
        }
        else
        {
          msg.description = msg.get_default_description();
        }

        for (const auto &fieldData : msgData["fields"]) {
          Field field;
          field.name = fieldData["name"].as<std::string>();
          field.type = fieldData["type"].as<std::string>();
          field.bigEndian = fieldData["big_endian"].as<bool>(false);
          if(fieldData["description"]) {
            field.description = fieldData["description"].as<std::string>();
          }
          else
          {
            field.description = field.get_default_description();
          }
          if (field.type == "enum") {
            const auto &enumData = fieldData["enum"];
            field.enumType.name = enumData["name"].as<std::string>();
            field.enumType.underlying_type =
                enumData["underlying_type"].as<std::string>("int");
            if (field.enumType.underlying_type.ends_with("_t")) {
              field.enumType.underlying_type = std::string("std::") + field.enumType.underlying_type;
            }
            if(enumData["description"]) {
              field.enumType.description = enumData["description"].as<std::string>();
            }
            else
            {
              field.enumType.description = field.get_default_description();
            }

            for (const auto &valueData : enumData["values"]) {
              EnumValue value;
              value.name = valueData["name"].as<std::string>();
              if(valueData["description"]) {
                value.description = valueData["description"].as<std::string>();
              }
              else
              {
                value.description = value.get_default_description();
              }

              value.value = valueData["value"].as<int>();
              field.enumType.values.push_back(value);
            }
          }
          else {
            if (field.type.ends_with("_t")) {
              field.type = std::string("std::") + field.type;
            }
          }

          msg.fields.push_back(field);
        }

        ns.messages.push_back(msg);
      }

      namespaces.push_back(ns);
    }
  } else {
    std::cerr << "Invalid YAML file format.\n";
    return;
  }

  std::string code = generateCode(namespaces);

  std::ofstream outputFileStream(outputFile);
  if (!outputFileStream) {
    std::cerr << "Failed to create output file.\n";
    return;
  }

  outputFileStream << code;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_yaml_file> [output_file]\n";
        return 1;
    }

    std::string yamlFile = argv[1];
    std::string outputFile;

    if (argc >= 3) {
        outputFile = argv[2];
    } else {
        // Set default output file path
        size_t extensionPos = yamlFile.rfind('.');
        if (extensionPos != std::string::npos) {
            outputFile = yamlFile.substr(0, extensionPos) + ".hh";
        } else {
            outputFile = yamlFile + ".hh";
        }
    }

    generateCppFile(yamlFile, outputFile);

    return 0;
}
