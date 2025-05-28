#!/usr/bin/env python3
"""Generate constants from YAML command definitions."""

import argparse
import os
import sys
from pathlib import Path
from typing import Any

import yaml


def load_yaml_file(file_path: Path) -> dict[str, Any]:
    """Load a YAML file and return its contents.

    Args:
        file_path: Path to yaml file.

    Returns:
        the loaded YAML content as a dictionary.
    """
    with Path(file_path).open(encoding="utf-8") as file:
        return yaml.safe_load(file)


def process_yaml_files(
    commands_dir: Path,
    common_dir: Path,
) -> list[dict[str, Any]]:
    """Process all command YAML files with anchor resolution.

    Args:
        commands_dir: Directory containing command YAML files.
        common_dir: Directory containing common YAML files to prepend.

    Returns:
        A list of command definitions with common content prepended.
    """
    commands = []

    # First, collect all common files as raw text
    common_content = ""

    if common_dir.exists():
        for file_path in common_dir.glob("*.yaml"):
            try:
                common_content += file_path.read_text(encoding="utf-8") + "\n"
                print(f"Loaded common file: {file_path.name}")
            except Exception as e:
                print(f"Error loading common file {file_path}: {e}")

    # Now process each command file with the common content prepended
    for root, _, files in os.walk(commands_dir):
        for file in files:
            if file.endswith((".yaml", ".yml")):
                file_path = Path(root) / file
                try:
                    command_content = file_path.read_text(encoding="utf-8")
                    # Combine common content with command content
                    combined_content = common_content + command_content

                    # Parse the combined content
                    command = yaml.safe_load(combined_content)
                    if command and "name" in command:
                        commands.append(command)
                        print(f"Added command: {command['name']}")

                except Exception as e:
                    print(f"Error processing {file_path}: {e}")

    return commands


def generate_constants_file(
    commands: list[dict[str, Any]],
    output_file: Path,
    runtime_collection_name: str,
) -> None:
    """Generate the constants.py file from command definitions.

    Args:
        commands: List of command definitions.
        output_file: Path to output constants file.
        runtime_collection_name: Name of the runtime collection class.
    """
    # Start with the base classes
    output = '''"""Constants for the dawmons contained for the instrument server."""


class BASE_COMMAND:
    """Contains the substrings for a base command."""

    @property
    def COMM_CHANNEL(self) -> str:
        """This is the communication channel to issue the command on."""
        msg = "This is an abstract base class. Must implement in subclass."
        raise NotImplementedError(msg)


class RESPONSE(BASE_COMMAND):
    """A response contains a timestamp."""

    @property
    def TIMESTAMP(self) -> str:
        """This is the timestamp when the response was completed."""
        return "timestamp"

'''

    # Generate a class for each command
    for command in commands:
        class_name = command["name"]
        # Check if timestamp is in any of the parameters
        has_timestamp = False
        if "parameters" in command:
            params = command["parameters"]
            if isinstance(params, dict) and "timestamp" in params:
                has_timestamp = True

        parent_class = "RESPONSE" if has_timestamp else "BASE_COMMAND"

        output += f'''
class {class_name}({parent_class}):
    """The substrings necessary for {command.get("description", "").lower() if "description" in command else class_name.lower()}."""

    @property
    def COMM_CHANNEL(self) -> str:
        """This is the communication channel to issue the command on."""
        return "{class_name}"
'''

        # Add properties for each parameter
        if "parameters" in command and isinstance(command["parameters"], dict):
            for param_name, param_def in command["parameters"].items():
                # Skip timestamp which is already included in RESPONSE
                if param_name == "timestamp" and parent_class == "RESPONSE":
                    continue

                # Handle simple parameters or complex parameter definitions
                if isinstance(param_def, dict) and "type" in param_def:
                    snake_case_name = param_name.upper()
                    description = param_def.get(
                        "description", f"This is the {param_name.lower()} parameter."
                    )

                    output += f'''
    @property
    def {snake_case_name}(self) -> str:
        """{description}"""
        return "{param_name}"
'''

    # Generate the final constants container class
    output += f'''

class {runtime_collection_name}:
    """All of the various runtime commands that a compiler may use."""

'''

    for command in commands:
        class_name = command["name"]
        output += f"    {class_name} = {class_name}()\n"

    # Write the output to the file
    with output_file.open("w", encoding="utf-8") as file:
        file.write(output)


def main():
    """Main entry point for the script."""
    parser = argparse.ArgumentParser(
        description="Generate constants.py from YAML command definitions"
    )
    parser.add_argument(
        "--api-dir",
        type=str,
        help="Directory containing the API definition files (default: api)",
        default="api",
    )
    parser.add_argument(
        "--commands-dir",
        type=str,
        help="Subdirectory within API dir containing command files (default: commands/v1)",
        default="commands/v1",
    )
    parser.add_argument(
        "--common-dir",
        type=str,
        help="Subdirectory within API dir containing common files (default: common)",
        default="common",
    )
    parser.add_argument(
        "--output",
        type=str,
        help="Output Python file (default: constants.py)",
        default="constants.py",
    )
    parser.add_argument(
        "--runtime-class",
        type=str,
        help="Name of the runtime collection class (default: INTERPRETER_RUNTIME_COMMANDS)",
        default="INTERPRETER_RUNTIME_COMMANDS",
    )

    args = parser.parse_args()

    # Resolve paths
    base_dir = Path.cwd()
    api_dir = base_dir / args.api_dir
    commands_dir = api_dir / args.commands_dir
    common_dir = api_dir / args.common_dir
    output_file = base_dir / args.output

    if not api_dir.exists():
        print(f"Error: API directory not found: {api_dir}")
        return 1

    if not commands_dir.exists():
        print(f"Error: Commands directory not found: {commands_dir}")
        return 1

    print(f"API dir: {api_dir}")
    print(f"Commands dir: {commands_dir}")
    print(f"Common dir: {common_dir}")
    print(f"Output file: {output_file}")

    commands = process_yaml_files(
        commands_dir=commands_dir,
        common_dir=common_dir,
    )
    generate_constants_file(
        commands=commands,
        output_file=output_file,
        runtime_collection_name=args.runtime_class,
    )
    print(f"Generated constants file at {output_file}, found {len(commands)} commands")
    return 0


if __name__ == "__main__":
    sys.exit(main())
