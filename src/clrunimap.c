/*
 * clrunimap.c
 *
 * Note: nowadays this kills kernel console output!
 */
#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <linux/kd.h>
#include "kdmapop.h"
#include "getfd.h"
#include "nls.h"

int
main(int argc, char *argv[]) {
	int fd;
	char *console = NULL;

	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE_NAME, LOCALEDIR);
	textdomain(PACKAGE_NAME);

	if (argc >= 3 && !strcmp(argv[1], "-C"))
		console = argv[2];

	if ((fd = getfd(console)) < 0)
		kbd_error(EXIT_FAILURE, 0, _("Couldn't get a file descriptor referring to the console"));

	return loadunimap (fd, NULL, NULL);
}
