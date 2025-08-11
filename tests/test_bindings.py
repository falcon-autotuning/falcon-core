import unittest
import json
import falcon_core
import sys

# Test that we can subclass a C++ director class in Python
class MyPythonJsonable(falcon_core.Jsonable):
    def __init__(self, name, value):
        super().__init__()
        self.name = name
        self.value = value
    
    def to_json(self):
        # This method overrides the C++ pure virtual method.
        # It needs to return a JSON string, as per our SWIG typemap.
        j = {
            "name": self.name,
            "value": self.value,
            "__module__": "test_bindings",
            "__class__": "MyPythonJsonable"
        }
        return json.dumps(j)
    
    def hash(self):
        return hash(self.name) ^ hash(self.value)

class TestBindings(unittest.TestCase):
    def test_time(self):
        t = falcon_core.Time()
        self.assertIsInstance(t.time(), int)
        self.assertGreater(t.time(), 1609459200) # Greater than 2021-01-01

    def test_units(self):
        # Create a dimension for length
        len_dims = falcon_core.DimensionMap({falcon_core.BaseDimension.LENGTH: 1})
        dim_len = falcon_core.Dimension(len_dims)
        self.assertFalse(dim_len.is_dimensionless())

        # Create a meter unit
        meter_unit_ptr = falcon_core.Unit(1.0, dim_len)
        self.assertIsInstance(meter_unit_ptr, falcon_core.Unit)

        # Create a SymbolUnit for meters
        meter = falcon_core.SymbolUnit(meter_unit_ptr, "m")
        self.assertEqual(meter.symbol(), "m")
        
        # Test with prefix
        km = meter.with_prefix("k")
        self.assertEqual(km.symbol(), "km")

        # Test conversion
        m_unit = meter.unit()
        km_unit = km.unit()
        self.assertAlmostEqual(km_unit.get_conversion_factor(m_unit), 1000.0)

    def test_jsonable_director(self):
        py_obj = MyPythonJsonable("py_obj", 123)
        
        # Test calling the overridden method directly from python
        json_str = py_obj.to_json()
        data = json.loads(json_str)
        self.assertEqual(data["name"], "py_obj")
        self.assertEqual(data["value"], 123)
        self.assertEqual(data["__class__"], "MyPythonJsonable")
        
        # This will call our C++ helper function.
        # The C++ code will then call `to_json` on the object.
        # Because of directors, this should call back into our Python `MyPythonJsonable.to_json`
        json_str_from_cpp = falcon_core.test_director_call(py_obj)
        data_from_cpp = json.loads(json_str_from_cpp)
        self.assertEqual(data_from_cpp["name"], "py_obj")

if __name__ == '__main__':
    unittest.main()
