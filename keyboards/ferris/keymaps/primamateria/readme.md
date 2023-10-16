```
make CONVERT_TO=promicro_rp2040 ferris/sweep:sweep:primamateria:uf2-split-left
make CONVERT_TO=promicro_rp2040 ferris/sweep:sweep:primamateria:uf2-split-right
```

It should be enough to copy the produced uf2 files to the usb drive that appears
when the board the board is reset with the bootloader.

The bitlocker will unfortunately allow to mount it read-only.
