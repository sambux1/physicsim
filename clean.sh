# suppress 'no such file or directory'
exec 2> /dev/null

rm -r build/
rm -r dist/
rm -r physicsim.egg-info/
rm -r tests/__pycache__/

find . -name '*.gch' -delete
find . -name '*.o' -delete
find . -name '*.out' -delete
