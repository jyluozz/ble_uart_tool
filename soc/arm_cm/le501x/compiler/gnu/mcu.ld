MEMORY
{
  RAM (rwx) : ORIGIN = 0x0000, LENGTH = 0xc000
  FLASH (rx) : ORIGIN = 0x18002000, LENGTH = 0x80000
}

INCLUDE common.ld