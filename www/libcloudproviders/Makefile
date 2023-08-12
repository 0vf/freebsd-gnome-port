PORTNAME=	libcloudproviders
DISTVERSION=	0.3.2
CATEGORIES=	www

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DBus API that allows cloud storage sync clients to expose services
WWW=		https://gitlab.gnome.org/World/libcloudproviders

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		meson pkgconfig
USE_LDCONFIG=   yes
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World

.include <bsd.port.mk>
