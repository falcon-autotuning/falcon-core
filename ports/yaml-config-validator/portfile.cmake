
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO falcon-autotuning/yaml-config-validator
    REF v${VERSION}
    SHA512 dff25d63b4f702df8fb94351d04284a93fd83a5ed2890b7c3a5ecfd008cf06f601ce81cabb5deb717ea40b3d963f7797882d5573dc15a0a327cf761ac06eef27
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup()

file(INSTALL "${SOURCE_PATH}/LICENSE"
     DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
     RENAME copyright)

vcpkg_copy_pdbs()
