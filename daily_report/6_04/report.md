I used this USB wifi receiver to connect to wi-fi. The official vendor says that this one isn't compatible with Linux OS, but I did not realize that when I bought it.

https://www.buffalo.jp/product/detail/wi-u2-433dhp.html


Searching on the web, I realized that there's a driver for this developed by an open-source community on (github)[https://github.com/abperiasamy/rtl8812AU_8821AU_linux] I cloned the repository and proceeded the setup, but I ended up facing a different problem due to my Internet configuration. I gave up on working on this problem with the same receiver, so I ordered a different (wi-fi card)[https://www.intel.com/content/www/us/en/products/docs/wireless-products/dual-band-wireless-ac-8265-desktop-kit-brief.html] from Intel. 

Also, I'm assuming that this Jetson nano would be on the chassis while operating so that it can do AI inference in real-time with sensors. Although because I'm guessing that this won't have a full self-driving functionality in the end, but rather it remains partially autonomous, it makes sense to control nano over some communication channel, such as wifi and bluetooth. 

In hope with this, I tested ssh connection with my laptop and nano. This worked fine when nano is connected to Ethernet(wired), but it didn't wirelessly with the receiver I mentioned above. I think this is because of the configuration of my Internet.

