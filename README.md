# teatime
![C build](https://github.com/jordiprats/teatime/workflows/C%20build/badge.svg?branch=master)

Timer for tea

Usage:

```
teatime <minutes>
```

It will notify showing the following image that the minutes you have specified have passed

![tea time](https://raw.githubusercontent.com/jordiprats/teatime/master/alarm.bmp "It's tea time!")

You can leave this command on any virtual desktop, the image will show up in any desktop you are working on

This is a rewrite of something I did circa 2006

## dependencies

Ubuntu 16.04: 

```
apt-get install libsdl2-dev -y
```

## build

```
make
```

## install

```
sudo make install
```
