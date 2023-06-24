## rsync for tunneling

[Corey's Tutorial](https://www.youtube.com/watch?v=qE77MbDnljA)

+ TODO:  <11-09-22> insert images  +

```sh
$ rsync "source dir/*" "backup/"  
```

Recursively sync. Only new files created prior to past sync, get copied.

```sh
$ rsync -r "source dir/*" "backup/"  
```

For symlinks, permissions, modification times, groups, owners etc.

```sh
$ rsync -a "source dir/*" "backup/"  
```

For checking before syncing. 

```sh
$ rsync -av --dry-run "source dir/*" "backup/"  
```

If backup is updated, then 

```sh
$ rsync -av --delete --dry-run "source dir/*" "backup/"  
```

For local and remote machines. Please setup keybased authentication for your server.

```sh
$ rsync -zaP "source dir" username@ip:"destination dir"
```
