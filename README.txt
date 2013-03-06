---------------------------------------------------------------------------
------                          COPYRIGHT                            ------
---------------------------------------------------------------------------

This file is made available under the Creative Commons CC0 1.0 Universal
Public Domain Dedication.

The person who associated a work with this deed has dedicated the work to
the public domain by waiving all of his or her rights to the work worldwide
under copyright law, including all related and neighboring rights, to the
extent allowed by law. You can copy, modify, distribute and perform the
work, even for commercial purposes, all without asking permission. 

However, the flac.exe and metaflac.exe binaries this project relies on (and
which are usually bundled) are licensed under GPL.

---------------------------------------------------------------------------
------                             FAQ                               ------
---------------------------------------------------------------------------

1) Why is this command line thing popping up?
FLAC frontend is a very simple program that just calls the 'real' FLAC
encoder, which is command line based. This has been done to keep
development of FLAC frontend easy and accessible and makes it possible to
change the encoder without having to change anything in the FLAC frontend

2) Is there drag and drop support?
Yes, there is. Just drag any files or directories to the list box in the
top left of the FLAC frontend window. Any directories will automatically be
searched (recursively) for .flac, .ogg, .oga and .wav files.

3) I encoded/decoded/tested/fingerprinted a lot of files, left it running
for a while, and now I can't see the results for the topmost ones any more!
The Windows command line works with a buffer that has usually a max of 300
lines. If you want to increase this, right click the icon in the top left
corner of the command line window and choose properties. Search for an
option called console buffer size (or something like that) and increase the
max number of lines.

4) FLAC frontend doesn't accept file names that contain foreign characters!
That's a problem with the FLAC encoder that is being worked on. Sorry




















































