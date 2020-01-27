# Lists all the exported function names in the created libraries.
nm -g --defined-only .\build\src\partition\libSimfsPartition.a
nm -g --defined-only .\build\src\volume\libSimfsVolume.a
write-host #newline
