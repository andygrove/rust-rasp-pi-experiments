extern crate libc;

#[link(name="opencvexample")]
extern {
  fn video_init() -> i32;
  fn video_grab() -> i32;
}


fn main() {
  let i = unsafe { video_init() };
  if i==0 {
    loop {
      let j = unsafe { video_grab() };
      if j != 0 {
        break;
      }
    }
  }
}
