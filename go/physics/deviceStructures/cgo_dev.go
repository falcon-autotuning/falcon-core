//go:build dev
// +build dev

package devicestructures

/*
   #cgo CFLAGS: -I../../../include -I../../../c-api/include -I../../../vcpkg_installed/x64-linux/include
	 #cgo LDFLAGS: -L../../../c-api/build -lfalcon_core_c_api -L../../../build -lfalcon_core_cpp
	 #include <stdlib.h>
   #include "falcon_core/physics/device_structures/Connection_c_api.h"
*/
import "C"
