let WebPlatformUUIDGenerator = {
    $Utils: {
        allocateString: function (str) {
            return allocate(intArrayFromString(str), ALLOC_STACK);
        },
    },
    GetWebUUID: function () {
        try {
            if (window.crypto && window.crypto.randomUUID) {
                return Utils.allocateString(window.crypto.randomUUID());
            }
        } catch (e) {
        }
        return null;
    }
}

autoAddDeps(WebPlatformUUIDGenerator, '$Utils');
mergeInto(LibraryManager.library, WebPlatformUUIDGenerator);