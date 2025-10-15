//go:build installed
// +build installed

package devicestructures

/*
#cgo CFLAGS: -I/usr/local/include
#cgo LDFLAGS: -L/usr/local/lib -lfalcon_core_c_api -lfalcon_core_cpp
#include <stdlib.h>
#include "falcon_core/physics/device_structures/Connection_c_api.h"
*/
import "C"
