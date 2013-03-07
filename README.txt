---------------------------------------------------------------------------
------                          COPYRIGHT                            ------
---------------------------------------------------------------------------

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

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




















































