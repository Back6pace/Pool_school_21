usage: git clone [<options>] [--] <repo> [<dir>]
    -v, --verbose         be more verbose
    -q, --quiet           be more quiet
    --progress            force progress reporting
    -n, --no-checkout     don't create a checkout
    --bare                create a bare repository
    --mirror              create a mirror repository (implies bare)
    -l, --local           to clone from a local repository
    --no-hardlinks        don't use local hardlinks, always copy
    -s, --shared          setup as shared repository
    --recursive           initialize submodules in the clone
    --recurse-submodules  initialize submodules in the clone
    --template <template-directory>     directory from which templates will be used
    --reference <repo>    reference repository
    --dissociate          use --reference only while cloning
    -o, --origin <name>   use <name> instead of 'origin' to track upstream
    -b, --branch <branch>    checkout <branch> instead of the remote's HEAD
    -u, --upload-pack <path>     path to git-upload-pack on the remote
    --depth <depth>       create a shallow clone of that depth
    --single-branch               clone only one branch, HEAD or --branch
    --separate-git-dir <gitdir>   separate git dir from working tree
    -c, --config <key=value>    set config inside the new repository
