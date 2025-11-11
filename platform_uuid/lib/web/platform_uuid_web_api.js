let WebPlatformUUIDGenerator = {
    GetWebUUID: function () {
        try {
            if (window.crypto && window.crypto.randomUUID) {
                let str = window.crypto.randomUUID();
                return stringToNewUTF8(str);
            }
        } catch (e) {
        }
        return null;
    }
}

mergeInto(LibraryManager.library, WebPlatformUUIDGenerator);