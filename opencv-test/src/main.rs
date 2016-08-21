extern crate libc;

use libc::c_char;
use std::ffi::CStr;
use std::ffi::CString;

#[link(name="opencvexample")]
extern {
  fn video_init() -> i32;
  fn video_grab(text: *const c_char) -> i32;
  fn video_close() -> i32;
}


fn main() {
  let i = unsafe { video_init() };
  println!("video_init() returned {}", i);
  if i==0 {
    for frame in 0 .. 100 {
      let text = CString::new(format!("Frame: {}", frame)).unwrap(); 
      let j = unsafe { video_grab(text.as_ptr()) };
      if j != 0 {
        break;
      }
    }
    unsafe { video_close() };
    println!("Finished");
  }
}
