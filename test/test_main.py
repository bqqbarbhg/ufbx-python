import pytest
import ufbx

def test_loading():
    is_thread_safe = ufbx.is_thread_safe()
    assert is_thread_safe
