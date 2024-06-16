ffmpeg -loglevel panic -i /dev/video0 -frames 1 -f image2 - | convert - -colorspace gray output_image.png
grep -i 'a' /usr/share/dict/words | grep -i 'a.*a.*a' | grep -vi 's$' | sed -E 's/.*(..)$/\1/' | sort | uniq | wc -l
