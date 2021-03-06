/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_MAPBOXONLINEREVERSEGEOCODINGSERVICE_H_
#define _CARTO_MAPBOXONLINEREVERSEGEOCODINGSERVICE_H_

#if defined(_CARTO_GEOCODING_SUPPORT)

#include "geocoding/ReverseGeocodingService.h"

namespace carto {

    /**
     * An online reverse geocoding service that uses MapBox geocoder.
     * As the class connects to an external (non-CARTO) service, this class is provided "as-is",   
     * future changes from the service provider may not be compatible with the implementation.
     * Geocoding and reverse geocoding perform network requests and must be executed in non-UI background thread.
     * Be sure to read the Terms and Conditions of the MapBox service to see if the
     * service is available for your application.
     * Note: this class is experimental and may change or even be removed in future SDK versions.
     */
    class MapBoxOnlineReverseGeocodingService : public ReverseGeocodingService {
    public:
        /**
         * Constructs a new instance of the MapBoxOnlineReverseGeocodingService given API key.
         * @param accessToken The access token to use (registered with MapBox).
         */
        explicit MapBoxOnlineReverseGeocodingService(const std::string& accessToken);
        virtual ~MapBoxOnlineReverseGeocodingService();

        /**
         * Returns the custom backend service URL.
         * @return The custom backend service URL. If this is not defined, an empty string is returned.
         */
        std::string getCustomServiceURL() const;
        /**
         * Sets the custom backend service URL. 
         * The custom URL should contain tags "{query}" and "{access_token}" that will be substituted by the SDK.
         * @param serviceURL The custom backend service URL to use. If this is empty, then the default service is used.
         */
        void setCustomServiceURL(const std::string& serviceURL);

        virtual std::string getLanguage() const;
        virtual void setLanguage(const std::string& lang);

        virtual std::vector<std::shared_ptr<GeocodingResult> > calculateAddresses(const std::shared_ptr<ReverseGeocodingRequest>& request) const;

    protected:
        static const std::string MAPBOX_SERVICE_URL;

        const std::string _accessToken;
        std::string _language;
        std::string _serviceURL;

        mutable std::mutex _mutex;
    };
    
}

#endif

#endif
