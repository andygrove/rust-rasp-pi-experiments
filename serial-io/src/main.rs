extern crate serial;


use std::env;
use std::io;
use std::time::Duration;

use std::io::prelude::*;
use serial::prelude::*;

fn main() {
    println!("Connecting...");

    let mut port = serial::open("/dev/ttyAMA0").unwrap();

    port.reconfigure(&|settings| {
        settings.set_baud_rate(serial::Baud57600).unwrap();
        settings.set_char_size(serial::Bits8);
        settings.set_parity(serial::ParityNone);
        settings.set_stop_bits(serial::Stop1);
        settings.set_flow_control(serial::FlowNone);
        Ok(())
    }).unwrap();

    port.set_timeout(Duration::from_millis(5000)).unwrap();

    println!("Reading...");
    let mut buf = vec![0_u8; 50];
    let foo = port.read(&mut buf[..]).unwrap();

    println!("{:?}", buf);

}
