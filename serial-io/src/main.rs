extern crate serial;


use std::env;
use std::io;
use std::time::Duration;

use std::io::prelude::*;
use serial::prelude::*;

fn main() {
    println!("Hello, world!");

    let mut port = serial::open("/dev/ttyFOO").unwrap();

    port.reconfigure(&|settings| {
        settings.set_baud_rate(serial::Baud9600);
        settings.set_char_size(serial::Bits8);
        settings.set_parity(serial::ParityNone);
        settings.set_stop_bits(serial::Stop1);
        settings.set_flow_control(serial::FlowNone);
        Ok(())
    }).unwrap();

    // try!(port.set_timeout(Duration::from_millis(1000)));
    //
    let mut buf = vec![0_u8; 50];
    let foo = port.read(&mut buf[..]).unwrap();

    println!("{:?}", buf);

}
