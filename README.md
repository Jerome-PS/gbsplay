# gbsplay - A Gameboy sound player

[![Code coverage status](https://codecov.io/github/mmitch/gbsplay/coverage.svg?branch=master)](https://codecov.io/github/mmitch/gbsplay?branch=master)
[![Build status](https://github.com/mmitch/gbsplay/workflows/Build%20and%20Test/badge.svg?branch=master)](https://github.com/mmitch/actions)
[![CodeQL status](https://github.com/mmitch/gbsplay/workflows/CodeQL/badge.svg?branch=master)](https://github.com/mmitch/actions)

This program emulates the sound hardware of the Nintendo Gameboy.  It
is able to play the sounds from a Gameboy module dump (.GBS format).

Homepage/Repo:   https://github.com/mmitch/gbsplay/  
Email contact:   <gbsplay-dev@lists.uguu.de>  
Bug reports:     please send new bugs to the mailing list
                 or use the issue tracker at
                 https://github.com/mmitch/gbsplay/issues

gbsplay is compatible to GBSv1.  It uses a backwards compatible extension
to store additional information in the file.  The gbsplay package contains
the following parts:

 * `gbsplay`:    a console player
 * `gbsinfo`:    displays information about a gbs file

## License

```
(C) 2003-2006,2008 by Tobias Diedrich <ranma+gbsplay@tdiedrich.de>
                      Christian Garbs <mitch@cgarbs.de>
                      Maximilian Rehkopf <otakon@gmx.net>
                      Vegard Nossum <vegardno@ifi.uio.no>

Licensed under GNU GPL v1 or, at your option, any later version.
```
