extern crate serial;


use std::env;
use std::io;
use std::time::Duration;

use std::io::prelude::*;
use serial::prelude::*;

fn main() {
    println!("Connecting...");

    let mut port = serial::open("/dev/ttyUSB0").unwrap();

    port.reconfigure(&|settings| {
        settings.set_baud_rate(serial::Baud57600).unwrap();
        settings.set_char_size(serial::Bits8);
        settings.set_parity(serial::ParityNone);
        settings.set_stop_bits(serial::Stop1);
//        settings.set_flow_control(serial::FlowSoftware);
        Ok(())
    }).unwrap();

    port.set_timeout(Duration::from_millis(1000)).unwrap();

    
    loop {
//	println!("Reading...");
        let mut buf = vec![0_u8; 64];
        let n = port.read(&mut buf[..]).unwrap();

        for i in 0..n {
            print!("{}", buf[i] as char);
        }

    }   

/*
$GPGLL,3956.4210,N,10504.9321,W,132909.800,A,D*41
$GPGLL,3956.4210,N,10504.9320,W,132910.400,A,D*44
$GPGLL,3956.4210,N,10504.9320,W,132910.600,A,D*46
$GPGLL,3956.4210,N,10504.9320,W,132910.800,A,D*48
*/
}
