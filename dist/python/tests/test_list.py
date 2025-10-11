from falcon_core.generic.list import List


def test_serialization():
    list = List.create_empty()
    assert list.empty()
