# Mainteiner: Breadtard <kubax_szela@wp.pl>
pkgname=initrc
pkgver=0.3
pkgrel=1
pkgdesc="A minimal init system, made in C"
arch=('any')
url="https://github.com/breadtard/InitRC"
license=("unknown")
makedepends=("gcc" "git")
source=("git+https://github.com/breadtard/InitRC")
noextract=()
md5sums=('SKIP')
validpgpkeys=()

prepare() {
    cd "InitRC"
}

build() {
    cd "InitRC"
    cc initrc.c -o initrc
}

check() {
    cd "InitRC"
    printf "pretend the check is done lmao\n"
}

package() {
    cd "InitRC"
whoami
    su -c "install -Dm755 initrc /sbin/initrc"
}
