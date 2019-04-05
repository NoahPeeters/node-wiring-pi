{
  'targets': [
    {
      'target_name': 'nodeWiringPi',
      'sources': [
        'src/addon.cc',
        
        'src/wiringPi.cc',
        'src/softPwm.cc',
        'src/softTone.cc',
        'src/wiringPiI2C.cc',
        'src/wiringPiISR.cc',
        'src/wiringPiSPI.cc',
        'src/wiringSerial.cc',
        'src/wiringShift.cc',

        'src/extensions/extensions.cc',
        'src/extensions/drcSerial.cc',
        'src/extensions/max5322.cc',
        'src/extensions/max31855.cc',
        'src/extensions/mcp23s08.cc',
        'src/extensions/mcp23s17.cc',
        'src/extensions/mcp3002.cc',
        'src/extensions/mcp3004.cc',
        'src/extensions/mcp3422.cc',
        'src/extensions/mcp4802.cc',
        'src/extensions/mcp23008.cc',
        'src/extensions/mcp23016.cc',
        'src/extensions/mcp23017.cc',
        'src/extensions/pcf8574.cc',
        'src/extensions/pcf8591.cc',
        'src/extensions/sn3218.cc',
        'src/extensions/sr595.cc',

        'src/devlib/devlib.cc',
        'src/devlib/ds1302.cc',
        'src/devlib/gertboard.cc',
        'src/devlib/lcd.cc',
        'src/devlib/lcd128x64.cc',
        'src/devlib/maxdetect.cc',
        'src/devlib/piFace.cc',
        'src/devlib/piGlow.cc',
        'src/devlib/piNes.cc',

        'src/nodeWiringPi.cc'
      ],
      'include_dirs': [
        'wiringPi/wiringPi',
        'wiringPi/devLib',
	'<!(node -e \"require(\'nan\')\")'
      ],
      'libraries': [
        '-lwiringPi',
        '-lwiringPiDev'
      ],
      'cflags': [
        '-Wall',
        '-std=c++11',

      ],
      'conditions': [
        [ 'OS=="mac"', {
          'xcode_settings': {
            'OTHER_CPLUSPLUSFLAGS' : [ '-std=c++11', '-stdlib=libc++'],
            'MACOSX_DEPLOYMENT_TARGET': '10.9'
          }
        }],
      ],
    }
  ]
}
