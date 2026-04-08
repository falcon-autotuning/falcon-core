#header-only library

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO falcon-autotuning/cereal-xtensor
    REF v1.3.2
    SHA512 67e90fc01742ba896f25bb6359f600d0fafd93b3c41ce1773eb186e2609c000cabb3229f4f2215c4f829b87e3647704a156c971e667fc21807beab2a345e2137)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DCMAKE_BUILD_TYPE=Release
)

vcpkg_cmake_install()
file(INSTALL
    "${CURRENT_PACKAGES_DIR}/lib/cmake/cereal-xtensor"
    DESTINATION "${CURRENT_PACKAGES_DIR}/debug/share"
)
vcpkg_cmake_config_fixup()
file(INSTALL "${SOURCE_PATH}/LICENSE"
     DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
     RENAME copyright)
vcpkg_copy_pdbs()
