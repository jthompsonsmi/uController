/***************************************
 * usb.h based on sunkbd_hid.h
 * http://sourceforge.net/projects/ezhid
 * maintainer:
 * Arnim Laeuger
 * arnim@users.sourceforge.net
 ***************************************/



/* USB descriptor type */

/* Supported: */ 
#define USB_DT_DEVICE            0x01
#define USB_DT_CONFIG            0x02
#define USB_DT_STRING            0x03


/* Not Supported: */
#define USB_DT_INTERFACE         0x04
#define USB_DT_ENDPOINT          0x05


/* fundamental data type */
typedef unsigned char byte;
typedef unsigned short word;

//#include "vendor.id" 

/* the device descriptor */
static code byte dev_desc[] = {
   0x12, // bLength             : Length of Descriptor
   0x01, // bDescriptorType     : Descriptor Type = Device
   0x10, // bcdUSB (L)          : USB Specification Version 1.10 (L)
   0x01, // bcdUSB (H)          : USB Specification Version 1.10 (H)
   0x00, // bDeviceClass        : Device Class (0xff is Vendor Specific)
   0x00, // bDeviceSubClass     : Device Sub-Class (0xff is Vendor Specific)
   0x00, // bDeviceProtocol     : Device Protocol (0xff is Vendor Specific)
   0x40, // bMaxPacketSize0     : Maximum Packet Size for EP0
   0xfe, // idVendor (L)        : Vendor ID (L)
   0xff, // idVendor (H)        : Vendor ID (H)
   0xfe, // idProduct (L)       : Product ID (L)
   0xff, // idProduct (H)       : Product ID (H)
   0x00, // bcdDevice (L)       : Device Release Number (BCD,L)
   0x01, // bcdDevice (H)       : Device Release Number (BCD,H)
   0x01, // iManufacturer       : Manufacturer Index String
   0x02, // iProduct            : Product Index String
   0x00, // iSerialNumber       : Serial Number Index String
   0x01  // bNumConfigurations  : Number of Configurations in this Device
};

/* the configuration descriptor */
static code byte conf_desc[] = {
   0x09, // bLength             : Length of Descriptor
   0x02, // bDescriptorType     : Descriptor Type = Configuration
   0x3b, // wTotalLength (L)    : Total Length (L) including Interface and Endpoint
   0x00, // wTotalLength (H)    : Total Length (H)

   0x02, // bNumInterfaces      : One Interface in this Configuration

   0x01, // bConfigurationValue : Configuration Value Used by Set_Configuration Request
         //                       to Select this Configuration
   0x00, // iConfiguration      : Index of String Describing this Configuration
   0x80, // bmAttributes        : Attributes
   0x32, // MaxPower            : Maximum Power



   // Endpoint Descriptor
   0x07, // bLength             : Length of Descriptor
   0x05, // bDescriptorType     : Descriptor Type = Endpoint
   0x81, // bEndpointAddress    : Endpoint Address
   0x03, // bmAttributes        : Endpoint Attributes = INT
   0x02, // wMaxPacketSize (L)  : Maximum Packet Size (L)
   0x00, // wMaxPacketSize (H)  : Maximum Packet Size (H)
   0x0a, // bInterval           : Polling intervall in Milliseconds


};

/*
static code Byte report_desc_led[] = {
  

}
*/

/* language ID string descriptor */
static code byte string_langid[] = {0x04, 0x03, 0x00, 0x00};

/* manufacturer ID string */
static code byte string_mfg[] = {
  0x0C, 0x03,
  /* standard requests */
  'J',0,'T',0,'D',0,'E',0,'V',0
};

/* product string descriptor */
/*
code Byte string_prod[] = {
   0x1a, 0x03,
   'P',0, 'I',0, 'N',0, ' ',0, 'C',0, 'O',0, 'N',0, 'T',0,
   'R',0, 'O',0, 'L',0
};
*/

static data unsigned int string_index[2] = {
  (unsigned int) string_langid,
  (unsigned int) string_mfg
};


/* setup packet structure */
typedef struct {
  byte bmRequestType;
  byte bRequest;
  byte wValueL;
  byte wValueH;
  byte wIndexL;
  byte wIndexH;
  byte wLengthL;
  byte wLengthH;
} setup_data;

static xdata setup_data * data sdata = (xdata setup_data *)&SETUPDAT;
static xdata byte * data in0buf = (xdata byte *)&IN0BUF;
static xdata byte * data out0buf = (xdata byte *)&OUT0BUF;
static xdata byte * data out1buf = (xdata byte *)&OUT1BUF;
static xdata byte * data out2buf = (xdata byte *)&OUT2BUF;
static xdata byte * data in2buf = (xdata byte *)&IN2BUF;
static xdata byte * data in4buf = (xdata byte *)&IN4BUF;



