# Snippets for C++

This folder contains JSON snippets for C++ development. Below are the comments extracted from the `cpp.json` file for reference:

## General Information
- Place your snippets for C++ here. Each snippet is defined under a snippet name and has a prefix, body, and description.
- The prefix is what is used to trigger the snippet, and the body will be expanded and inserted.
- Possible variables are:
  - `$1`, `$2` for tab stops
  - `$0` for the final cursor position
  - `${1:label}`, `${2:another}` for placeholders. Placeholders with the same IDs are connected.

## Example
```json
"hello world": {
    "prefix": "hello, world",
    "body": [
        "#include<iostream>",
        "using namespace std;\n",
        "int main(){",
        "\tcout<<\"hello, world\"<<\"\\n\";",
        "\treturn 0;",
        "}"
    ]
}
```

## Notes
- Comments are not permitted in JSON files. This README serves as a reference for the comments that were originally present in the `cpp.json` file.
